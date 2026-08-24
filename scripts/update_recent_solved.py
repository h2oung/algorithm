from pathlib import Path
from urllib.parse import quote
import re
import subprocess

README = Path("README.md")
START = "<!-- RECENT_SOLVED_START -->"
END = "<!-- RECENT_SOLVED_END -->"
PLATFORMS = {"백준": "Baekjoon", "프로그래머스": "Programmers"}
LIMIT = 3


def git(*args):
    return subprocess.check_output(
        ["git", *args],
        text=True,
        encoding="utf-8",
        errors="replace",
    )


def clean_title(folder_name):
    title = re.sub(r"^\d+[.\s\u2000-\u200b\u3000]*", "", folder_name)
    return title or folder_name


def recent_problem_dirs():
    result = []
    seen = set()

    commits = git("log", "--format=%H").splitlines()

    for commit in commits:
        files = git(
            "show",
            "--pretty=format:",
            "--name-only",
            "--diff-filter=AM",
            commit,
        ).splitlines()

        for file_name in files:
            path = file_name.strip()
            if not path:
                continue

            parts = Path(path).parts

            if len(parts) < 3 or parts[0] not in PLATFORMS:
                continue

            problem_dir = Path(*parts[:3]).as_posix()

            if problem_dir in seen:
                continue

            seen.add(problem_dir)
            result.append(problem_dir)

            if len(result) == LIMIT:
                return result

    return result


def make_section(problem_dirs):
    lines = [
        "## ✦ Recent Solved",
        "",
        "|  | Problem | Platform |",
        "|:---:|:---|:---:|",
    ]

    symbols = ["✦", "⋆", "·"]

    for i, problem_dir in enumerate(problem_dirs):
        parts = Path(problem_dir).parts
        platform_ko, level, folder = parts[:3]

        platform = PLATFORMS[platform_ko]
        title = clean_title(folder)
        link = quote(problem_dir, safe="/")

        lines.append(
            f"| {symbols[i]} | [`{title}`]({link}) | {platform} · {level} |"
        )

    if not problem_dirs:
        return "## ✦ Recent Solved\n\n아직 최근 풀이가 없습니다."

    return "\n".join(lines)


def main():
    content = README.read_text(encoding="utf-8")

    if START not in content or END not in content:
        raise RuntimeError(
            "README.md에 RECENT_SOLVED_START / RECENT_SOLVED_END 마커가 없습니다."
        )

    section = make_section(recent_problem_dirs())

    before, rest = content.split(START, 1)
    _, after = rest.split(END, 1)

    updated = f"{before}{START}\n{section}\n{END}{after}"
    README.write_text(updated, encoding="utf-8")


if __name__ == "__main__":
    main()

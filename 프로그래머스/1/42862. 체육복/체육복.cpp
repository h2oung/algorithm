#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    // 1. 학생 번호 정렬
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // 2. 여벌 체육복도 가져오고 도난도 당한 학생 제거
    vector<int> realLost;

    for (int i = 0; i < lost.size(); i++) {

        auto it = find(reserve.begin(), reserve.end(), lost[i]);

        if (it != reserve.end()) {
            reserve.erase(it);
        }
        else {
            realLost.push_back(lost[i]);
        }
    }

    // 3. 실제 체육복이 없는 학생 수
    int answer = n - realLost.size();

    // 4. 앞번호 학생에게 먼저 빌려보기
    for (int i = 0; i < realLost.size(); i++) {

        int student = realLost[i];

        auto it = find(reserve.begin(), reserve.end(), student - 1);

        if (it != reserve.end()) {
            answer++;
            reserve.erase(it);
        }
        else {
            // 5. 앞번호가 없다면 뒷번호 학생 확인
            it = find(reserve.begin(), reserve.end(), student + 1);

            if (it != reserve.end()) {
                answer++;
                reserve.erase(it);
            }
        }
    }

    return answer;
}
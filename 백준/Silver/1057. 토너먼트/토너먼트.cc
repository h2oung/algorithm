#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, j, h;
    cin >> N >> j >> h;

    int round = 0;

    while (j != h) {
        j = (j + 1) / 2;
        h = (h + 1) / 2;
        round++;
    }

    cout << round << '\n';
    return 0;
}

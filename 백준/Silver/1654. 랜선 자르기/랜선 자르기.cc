#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, N;
    cin >> K >> N;

    vector<long long> cables(K);
    long long max_len = 0;

    for (int i = 0; i < K; ++i) {
        cin >> cables[i];
        max_len = max(max_len, cables[i]);
    }

    long long left = 1, right = max_len; // 탐색 범위 설정용
    long long answer = 0;

    while (left <= right) { 
        long long mid = (left + right) / 2;
        long long count = 0;

        for (int i = 0; i < K; ++i) {
            count += cables[i] / mid; 
        }

        if (count >= N) {
            answer = mid;     // 가능은 한데 너무 많이 나오니 길이를 늘리자
            left = mid + 1;
        } else {
            right = mid - 1;      // 너무 길어서 갯수가 적게 나옴. 길이를 줄이자
        }
    }

    cout << answer << "\n";
    return 0;
}
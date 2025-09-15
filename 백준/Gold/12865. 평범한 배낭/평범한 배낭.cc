#include <bits/stdc++.h>
using namespace std;

int N, K;
int W[101], V[101];
int dp[101][100001]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }

    for (int i = 1; i <= N; i++) {          // i번째 물건까지 고려
        for (int w = 0; w <= K; w++) {      // 현재 배낭 용량
            dp[i][w] = dp[i-1][w];          // 일단 안 넣는 경우
            if (w - W[i] >= 0) {            // 넣을 수 있으면
                dp[i][w] = max(dp[i][w], dp[i-1][w-W[i]] + V[i]);
            }
        }
    }

    cout << dp[N][K] << "\n";
    return 0;
}

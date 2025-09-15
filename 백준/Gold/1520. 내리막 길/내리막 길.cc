#include <bits/stdc++.h>
using namespace std;

int M,N;
int board[501][501];
int dp[501][501];
int dy[4]={1, -1, 0, 0};
int dx[4]={0, 0, 1, -1};

int dfs(int y, int x){
    if(y==M-1&&x==N-1) return 1;
    if(dp[y][x]!=-1) return dp[y][x];

    dp[y][x]=0;

    for(int dir=0; dir<4; dir++){
        int ny=y+dy[dir];
        int nx=x+dx[dir];

        if(ny<0 || nx<0 || ny >=M || nx >= N) continue;
        if(board[y][x] > board[ny][nx]) {
            dp[y][x]+=dfs(ny,nx);
        }
    }
    return dp[y][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> M >> N;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
            dp[i][j]=-1;
        }
    }

    cout << dfs(0, 0) << "\n";
    return 0;
}
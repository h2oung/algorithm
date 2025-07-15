#include<bits/stdc++.h>
using namespace std; 
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1}; 
int m, n, k, y, x, ret, ny, nx, t;
int a[51][51];
bool visited[51][51];  // 방문 여부 체크

void dfs(int y, int x){
    visited[y][x] = 1; // 방문 표시
    for(int i = 0; i < 4; i++){
        ny = y + dy[i]; 
        nx = x + dx[i]; // 현재 위치를 기준으로 상하좌우로 인접한 1을 탐색
        if(ny < 0 || nx < 0 || ny >=n || nx >= m) continue;
        if(a[ny][nx] == 1 && !visited[ny][nx]){
            dfs(ny, nx); // 재귀적으로 연결된 모든 1을 방문 처리
        }
    }
    return;
}

int main(){ 
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while(t--){ // 테스트 케이스만큼 반복
        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0); // fill로 케이스마다 초기화
        
        ret = 0;
        cin >> m >> n >> k; // 가로, 세로, 배추 갯수 입력
        for(int i = 0; i < k; i++){
            cin >> x >> y;
            a[y][x] = 1; // 배추 표시
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 1 && !visited[i][j]){
                    dfs(i, j);
                    ret++; // 한번 dfs를 돌 때마다 덩어리 추가
                }
            }
        }
        cout << ret << "\n"; // 덩어리 개수 출력
    }
    return 0;
}


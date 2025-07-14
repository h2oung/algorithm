#include <bits/stdc++.h>
using namespace std;
const int max_n = 104;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = { 0, 1, 0, -1};
// 각각 위, 오른쪽, 아래, 왼쪽

int n,m, a[max_n][max_n], visited[max_n][max_n], y, x;

int main() {
	scanf("%d %d", &n, &m); 
     for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    
    queue<pair<int, int>> q; 
    visited[0][0] = 1; // 처음 거리 1로 초기화
    q.push({0, 0});
    
    while(q.size()){
        tie(y, x) = q.front(); q.pop(); // q.front()로 묶음 꺼내서 각각 y, x에 저장, 큐에서 삭제
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i]; 
            int nx = x + dx[i]; 
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue; 
            if(visited[ny][nx]) continue; 
            visited[ny][nx] = visited[y][x] + 1; // 이동 거리 갱신
            q.push({ny, nx});  // 큐에 새 좌표 투입
        } 
    }
    printf("%d", visited[n - 1][m - 1]); 
    return 0;
}
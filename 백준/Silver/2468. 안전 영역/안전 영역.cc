#include<bits/stdc++.h>
using namespace std;   
int a[101][101], e[101][101], visited[101][101], n, temp, ret = 1;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int d){
    visited[y][x] = 1; 
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i]; 
        int nx = x + dx[i]; // 인접 지역 탐색
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue; 
        if(!visited[ny][nx] && a[ny][nx] > d) dfs(ny, nx, d); // 인접 지역에서 재귀 함수 
    }
    return;
} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);   
    cin >> n; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int d = 1; d < 101; d++){ // 비 높이를 바꾸는 로직
        fill(&visited[0][0], &visited[0][0] + 101 * 101, 0); 
        int cnt = 0;  
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] > d && !visited[i][j]) { // 그 높이보다 높은데 방문하지 않았으면
                    dfs(i, j, d); // 안전 지역 하나 탐색
                    cnt++; // 안전 지역 개수 +1
                }
            }
        }
        ret = max(ret, cnt); 
    }
    cout << ret << '\n';
    return 0; 
}
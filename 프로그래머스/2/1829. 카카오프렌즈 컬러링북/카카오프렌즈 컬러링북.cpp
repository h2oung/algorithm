#include <bits/stdc++.h>

using namespace std;

int dx[4]={1, 0, -1, 0};
int dy[4]={0, -1, 0, 1};

int bfs(int x, int y, vector<vector<int>>& picture, vector<vector<bool>>& visited) {
    int color = picture[y][x];
    
    queue<pair<int, int>> q;

    q.push({y,x});
    visited[y][x] = true;

    int cnt=1;
    
    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        
        q.pop();
        
        for(int k=0; k<4; k++){
            int nx = cx+dx[k];
            int ny = cy+dy[k];
            
            if(nx<0 || ny<0 || nx>=picture[0].size() || ny>=picture.size()){
                continue;
            }
            
            if (visited[ny][nx]==true|| picture[ny][nx]==0){
                continue;
            }
            
            if(picture[ny][nx]!=color){
                continue;
            }
            
            visited[ny][nx]=true;
            
            q.push({ny,nx});
            cnt++;
        }
        
    } return cnt;
    
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    
    vector<vector<bool>> visited(picture.size(), vector<bool>(picture[0].size(), false));
    
    for(int y=0; y<picture.size(); y++){
        for(int x=0; x<picture[0].size(); x++){
            
            if (picture[y][x] == 0 || visited[y][x]) {
               continue;
            }
            
            int cnt=bfs(x, y, picture, visited);
            max_size_of_one_area=max(cnt, max_size_of_one_area);
            number_of_area++;
        }
    }
    return {number_of_area, max_size_of_one_area};
}
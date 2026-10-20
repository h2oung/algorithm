#include <bits/stdc++.h>

using namespace std;

// k는 유저의 현재 피로도
// 각 던전별 최소 피로도, 소모 피로도가 담긴 2차원 배열
// 유저가 탐험할 수 있는 최대 던전수 리턴
int answer;

void dfs(int energy, int cnt, vector<vector<int>> &dungeons, vector<bool> &visited){
     
    answer=max(cnt, answer);
    
    for(int i=0; i<dungeons.size(); i++){
        if(energy>=dungeons[i][0] && visited[i]==false){
            visited[i]=true;
            dfs(energy-dungeons[i][1], cnt+1, dungeons, visited);
            visited[i]=false;
        } 
    }
    
    return;
    
}

int solution(int k, vector<vector<int>> dungeons) {
    answer=0;
    vector<bool> visited(dungeons.size(), false);
    dfs(k, 0, dungeons, visited);
    
    return answer;
}
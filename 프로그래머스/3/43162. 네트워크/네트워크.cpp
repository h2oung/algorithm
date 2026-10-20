#include <bits/stdc++.h>

using namespace std;

int cnt=0;

void dfs(int cur, vector<vector<int>> &computers, vector<bool> &visited){
    visited[cur]=true;
    
    for(int next=0; next<computers.size(); next++){
        if(computers[cur][next]==1 && visited[next]==false){
            dfs(next, computers, visited);
        }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n, false);
    
    for(int i=0; i<computers.size(); i++){
        if(visited[i]==false){
            dfs(i, computers, visited);
            cnt++;
        }
    }
    return cnt;
}


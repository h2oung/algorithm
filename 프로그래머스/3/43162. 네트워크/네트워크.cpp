#include <bits/stdc++.h>

using namespace std;


void dfs(int cur, vector<vector<int>> &computers, vector<bool> &visited){
    visited[cur]=true;
    for(int next=0; next<computers.size(); next++){
            if (computers[cur][next] == 1 && !visited[next]) {
                dfs(next, computers, visited);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visited(n, false);
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i, computers, visited);
            answer++;
        }
    }

    return answer;
}
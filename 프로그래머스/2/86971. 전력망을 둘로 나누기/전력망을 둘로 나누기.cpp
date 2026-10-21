#include <bits/stdc++.h>

using namespace std;
int cnt;
int answer=INT_MAX; 

void dfs(int k, vector<vector<int>> &temp, vector<bool> &visited){
    
    visited[k]=true;
    cnt++;
    
    for(int j=0; j<temp.size(); j++){
        
            int a = temp[j][0];
            int b = temp[j][1];
            
            if(a==k && visited[b]==false){
                dfs(b, temp, visited);
            }
        
            if(b==k && visited[a]==false){
                dfs(a, temp, visited);
            } 
        
        }
}


int solution(int n, vector<vector<int>> wires) {
    
    
    for(int i=0; i<wires.size(); i++){
        cnt = 0;
        vector<bool> visited(n+1, false);
        
        vector<vector<int>> temp = wires;
        temp.erase(temp.begin() + i);
        
        dfs(1, temp, visited);
        
        int diff = abs(cnt - (n - cnt));
        answer = min(answer, diff);
    }
    
    return answer;
}
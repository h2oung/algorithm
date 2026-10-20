#include <bits/stdc++.h>

using namespace std;

int cnt; 
int answer=INT_MAX;

bool oneDiff(string a, string b){
    int diff=0;
    for(int k=0; k<a.size(); k++){
        if(a[k]!=b[k]) diff++;
    }
    if(diff==1) return true;
    else return false;
}

void dfs(string s, string target, int cnt, vector<string> &words, vector<bool> &visited) {
    
    if(s==target){
        answer=min(answer,cnt);
        return;
    }
    
    for(int i=0; i<words.size(); i++){
        if(oneDiff(s, words[i]) && visited[i]==false){
            s=words[i];
            visited[i]=true;
            dfs(s, target, cnt+1, words, visited);
        }
    }           
}

int solution(string begin, string target, vector<string> words) {
    cnt = 0;
    
    vector<bool> visited(words.size(), false);
    
    dfs(begin, target, 0, words, visited);
    if(answer==INT_MAX) return 0;
    else return answer;
    
}
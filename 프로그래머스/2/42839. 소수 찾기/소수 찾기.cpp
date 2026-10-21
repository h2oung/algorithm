#include <bits/stdc++.h>

using namespace std;

int an; 

bool isPrime(int num){
    if(num<2) return false;
    
    for(int i=2; i*i<=num; i++){
        if(num%i==0){
            return false;
        } 
    }
    
    return true;
}

void dfs(string p, string numbers, vector<bool> &visited, set<int> &s) {
    
    if(!p.empty()){
        an=stoi(p);
        if(isPrime(an)==true){
            s.insert(an);
        }
    }
    
    
    for(int i=0; i<numbers.size(); i++){
        if(visited[i]==false){
            visited[i]=true;
            dfs(p+numbers[i], numbers, visited, s);
            visited[i]=false;
        }
    }
}

int solution(string numbers) {
    vector<bool> visited(numbers.size(), false);
    set<int> s;
    
    dfs("", numbers, visited, s);

    return s.size();
}
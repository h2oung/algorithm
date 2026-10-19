#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {

    vector<int> answer;
    
    queue<int> q;
    
    // 1. 남은 일수 각각 구하기
    for(int i=0; i<progresses.size(); i++){
        int remain;
        remain=((100-progresses[i])+speeds[i]-1)/speeds[i];
        
        q.push(remain);
    }
    
    while(!q.empty()){
        int ds;
        int cnt = 0;
        ds=q.front();
        
        while(!q.empty() && q.front()<=ds){
            cnt++;
            q.pop();
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
    
}
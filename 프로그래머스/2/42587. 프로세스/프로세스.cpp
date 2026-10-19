#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int, int>> q;
    int cnt=0;
    // pair.first  = 우선순위
    // pair.second = 원래 위치

    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
    }

    while(!q.empty()){
        auto cur = q.front();
        int f = cur.first;
        bool higher = false;
        q.pop();
        
        auto temp = q;
        
        while(!temp.empty()){
            if(temp.front().first>f) {
             higher=true;
             break;
            } temp.pop();
        }
        
        if(higher) {
            q.push(cur);
        } else {
            cnt++;
            if(cur.second==location) return cnt;
            
        }
    }
    
}
#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> mp;
    
    int answer=1;
    
    for(auto s: clothes){
        mp[s[1]]++;
    }
    
    for(auto c: mp){
        answer=answer*(c.second+1);
    }
    return answer-1;
}
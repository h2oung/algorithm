#include <bits/stdc++.h>

using namespace std;

// 가장 먼저 탈락하는 사람 번호와 자신의 몇번째 차례에 탈락하는지 (전체 몇번째 턴)
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int turn;
    bool end=false;
    map<string, int> mp;
    
    mp[words[0]]++;
    
    for(int i=1; i<words.size(); i++){
        mp[words[i]]++;
        char last_word = words[i-1].back();
        if(words[i][0]!=last_word || mp[words[i]]!=1) { 
            end=true;
            return {i%n+1, i/n+1};
            break;
        }
    }
    
    if(end==false){
        return {0, 0};
    }
}
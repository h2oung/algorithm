#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    unordered_map<string, int> mp;
    
    for(int i=0; i<participant.size(); i++){
        mp[participant[i]]++;
    }
    
    for(int j=0; j<completion.size(); j++){
        mp[completion[j]]--;
    }
    
    for(int p=0; p<participant.size(); p++){
        if(mp[participant[p]]>=1) return participant[p];
    }

}

/* completion 길이는 참여자 길이보다 1 작음
동명이인 있을 수 있음
완주하지 못한 선수 이름 리턴

unordered_map 활용하기!
for문 돌면서 

*/
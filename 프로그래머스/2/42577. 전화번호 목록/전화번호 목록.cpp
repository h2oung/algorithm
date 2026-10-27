#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {

    unordered_map<string, bool> mp;
    string prefix;
    
    for(string s: phone_book){
        mp[s]=true;
    }
    
    for(string s: phone_book){
        prefix="";
        for(int i=0; i<s.size()-1; i++){
            prefix+=s[i];
            
            if(mp.count(prefix)){
                return false;
            }
        }
    }
    
    return true;
}
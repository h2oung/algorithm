#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> mp;
    
    for(int i=0; i<want.size(); i++){
        mp[want[i]]=number[i];
    }
    
    for(int i=0; i<=discount.size()-10; i++){
        map<string, int> temp=mp;
        for(int j=i; j<=i+9; j++){
         temp[discount[j]]--;
        }
        
        bool possible = true;
        
        for (auto p : temp) {
            if (p.second != 0) {
              possible = false;
              break;
             }
        }
            
        if (possible) {
             answer++;
        }
        
    }
    
    return answer;
}
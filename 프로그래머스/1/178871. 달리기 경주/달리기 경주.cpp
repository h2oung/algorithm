
#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {

    unordered_map<string,int> mp;
    
    for (int i = 0; i < players.size(); i++) {
        mp[players[i]] = i;
    }
    
    for(string name: callings){
        int idx=mp[name];
        string front = players[idx - 1];
        swap(players[idx], players[idx-1]);
        mp[front]++;
        mp[name]--;
    }
    return players;
}

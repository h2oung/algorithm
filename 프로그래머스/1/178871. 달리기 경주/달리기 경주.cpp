
#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {

    unordered_map<string, int> mp;

    // 선수 이름별 현재 순위 저장 (0부터 시작)
    for (int i = 0; i < players.size(); i++) {
        mp[players[i]] = i;
    }

    for (string name : callings) {

        int idx = mp[name];

        // 앞 선수 이름
        string front = players[idx - 1];

        // 두 선수 위치 교환
        swap(players[idx], players[idx - 1]);

        // 변경된 위치를 map에도 반영
        mp[name] = idx - 1;
        mp[front] = idx;
    }

    return players;
}

#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> mp;

    // 1. 귤 크기별 개수 세기
    for (int i = 0; i < tangerine.size(); i++) {
        mp[tangerine[i]]++;
    }

    // 2. 등장 횟수만 vector에 저장
    vector<int> v;

    for (auto p : mp) {
        v.push_back(p.second);
    }

    // 3. 등장 횟수 내림차순 정렬
    sort(v.begin(), v.end(), greater<int>());

    // 4. 개수가 많은 종류부터 선택
    for (int i = 0; i < v.size(); i++) {
        k -= v[i];
        answer++;

        if (k <= 0) break;
    }

    return answer;
}
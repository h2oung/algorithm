#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    stringstream ss(s);
    vector<int> v;
    int num;

    while (ss >> num) {
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    return to_string(v.front()) + " " + to_string(v.back());
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, j;
    deque<int> d;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        if (s == "push_front") {
            cin >> j;
            d.push_front(j);
        } 
        else if (s == "push_back") {
            cin >> j;
            d.push_back(j);
        } 
        else if (s == "pop_front") {
            if (d.empty()) cout << -1 << '\n';
            else {
                cout << d.front() << '\n';
                d.pop_front();
            }
        } 
        else if (s == "pop_back") {
            if (d.empty()) cout << -1 << '\n';
            else {
                cout << d.back() << '\n';
                d.pop_back();
            }
        } 
        else if (s == "size") {
            cout << d.size() << '\n';
        } 
        else if (s == "empty") {
            cout << (d.empty() ? 1 : 0) << '\n';
        } 
        else if (s == "front") {
            if (d.empty()) cout << -1 << '\n';
            else cout << d.front() << '\n';
        } 
        else if (s == "back") {
            if (d.empty()) cout << -1 << '\n';
            else cout << d.back() << '\n';
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    queue<int> s;

    while (N--) {
        string cmd; 
        cin >> cmd;

        if (cmd == "push") {
            int x;
            cin >> x;
            s.push(x);
        }
        else if (cmd == "pop") {
            if (s.empty()) cout << -1 << '\n';
            else {
                cout << s.front() << '\n';
                s.pop();
            }
        }
        else if (cmd == "size") {
            cout << s.size() << '\n';
        }
        else if (cmd == "empty") {
            cout << (s.empty() ? 1 : 0) << '\n';
        }
        else if (cmd == "front") {
            if (s.empty()) cout << -1 << '\n';
            else cout << s.front() << '\n';
        }
        else if (cmd == "back") {
            if (s.empty()) cout << -1 << '\n';
            else cout << s.back() << '\n';
        }
    }

}

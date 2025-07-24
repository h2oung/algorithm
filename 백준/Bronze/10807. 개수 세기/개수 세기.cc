#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, p, count = 0;
    vector<int> v;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    cin >> p;

    for(int i = 0; i < n; i++) {
        if(v[i] == p) {
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}

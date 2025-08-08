#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, x;
    cin >> a >> b;
    vector<int> v;

    for(int i=0; i<a; i++){
        cin >> x;
        v.push_back(x);
    }

    for(int i=0; i<b; i++){
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    
    for(int j : v) {
        cout << j << " ";
    }
}
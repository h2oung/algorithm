#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, x;
    cin >> N;

    set<int> s;

    for(int i=0; i<N; i++){
        cin >> x;
        s.insert(x);
    }


    for(int i : s) {
        cout << i << "\n";
    }
}
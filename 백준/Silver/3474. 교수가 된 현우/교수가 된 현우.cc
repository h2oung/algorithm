#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, a;
    cin >> n;
    while (n--) {
        cin >> a;
        int ret = 0;
        for (int i = 5; i <= a; i *= 5) {
            ret += a / i;
        }
        cout << ret << "\n";
    }
}

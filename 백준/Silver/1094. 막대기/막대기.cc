#include <bits/stdc++.h>
using namespace std;

int main() {
    int X;
    cin >> X;

    int count = 0;
    while (X > 0) {
        count += (X & 1); 
        X >>= 1;          
    }

    cout << count << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    
    cin.tie(NULL);
    ios::sync_with_stdio(false); // c와 c++의 버퍼를 분리하는 역할
    int t;
    cin >> t; 
    
    for(int i=0; i<t; i++){
        int A, B;
        cin >> A >> B;
        cout << A + B << "\n";
    }
    return 0;
}
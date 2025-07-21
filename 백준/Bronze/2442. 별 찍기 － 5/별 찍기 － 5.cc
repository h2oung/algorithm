#include <bits/stdc++.h>
using namespace std;

int main(void){
    int k;
    cin >> k;
    
    for(int i=0; i<k; i++){
        for(int p=0; p<k-(i+1); p++){
             cout << " ";
        }
       
        for(int j=0; j< 2*i+1; j++){
            cout << "*";
        }
        cout << endl;
    }
} 
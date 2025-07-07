#include<bits/stdc++.h> 
using namespace std;   
int n; 
string s, ori_s, pre, suf; 
int main(){
    cin >> n;
    cin >> ori_s;   
    int pos = ori_s.find('*');     // * 문자가 어디에 있는지 위치 찾음
    pre = ori_s.substr(0, pos);  
    suf = ori_s.substr(pos + 1); 
    for(int i = 0; i < n; i++){
        cin >> s;      
        if(pre.size() + suf.size() > s.size()){
            cout << "NE\n"; // *를 제외하고 pre랑 suf 합친 것만큼은 최소한 가지고 있어야 함. 1차 필터링
        }else{
            if(pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) cout << "DA\n";
            else cout <<"NE\n";  
        } // pre, suf 일치 여부 확인
    } 
    return 0;
}
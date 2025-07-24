#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, m;
    cin >> n >> k >> m;
    
    deque<int> dq;
    for(int i=1; i<=n; i++) dq.push_back(i); // 1 2 3  ...  n 순서로 덱 형성
    
    int count = 0;
    bool direction = true; //정방향 
    
    while(!dq.empty()) { // 다 빠질 때까지
        if(direction) {
            for(int i=0; i<k-1; i++){
                dq.push_back(dq.front());
                dq.pop_front(); // 앞에 k-1을 뒤에 push하고 pop으로 빼냄
            }
            cout << dq.front() << "\n";
            dq.pop_front(); // k번째 해당하는거 출력하고 pop
        } else {
            for(int i=0; i<k-1; i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cout << dq.back() << "\n";
            dq.pop_back();
        }
        count++; // 방향 뒤집을거 카운트
        if(count==m){
            direction=!direction; // m이 되면 방향 뒤집고
            count=0; // count도 처음부터 다시 세기
        }
    }
}
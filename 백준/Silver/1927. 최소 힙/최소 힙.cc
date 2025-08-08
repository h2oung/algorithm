#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,x;
    cin >> N;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    // < 자료형, 내부저장용컨테이너, 정렬기준 > 
    // 최대힙 기본형에서 최소힙으로 변경
    
     for (int i = 0; i < N; i++) {
        cin >> x;
        if (x == 0) {
            if (pq.empty()) {
                cout << 0 << '\n';
            } else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }
}
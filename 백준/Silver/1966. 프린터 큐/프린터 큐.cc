#include <bits/stdc++.h>
using namespace std;

int main(void){
     int t;
     int n, m, pr;
    
    cin >> t; // 테스트케이스 입력받음
    
    for(int i=0; i<t; i++){
        int cnt=0; // 출력 순서를 저장할 변수, 즉 이 문제에서는 정답
        queue<pair<int, int>> q; // 문서의 인덱스와 중요도를 저장하는 pair큐
        priority_queue<int> printer; // 가장 높은 중요도를 알기 위한 우선순위큐
        
        cin >> n >> m; // 문서 갯수랑 구하고자 하는 문서의 인덱스
        
        for(int j=0; j<n; j++){ // j는 각 문서의 초기 인덱스
                cin >> pr; 
                q.push({j, pr}); // j는 for문 돌려서 순서 인덱스 만들고 중요도 큐에 저장
                printer.push(pr); // 중요도는 또 따로 우선순위 큐에 저장
        }
         
        while(!printer.empty()){ // 기저조건
            
            int idx = q.front().first; // 현재 맨 앞 문서의 인덱스 
            int prior = q.front().second; // 현재 맨 앞 문서의 우선순위 
            
            q.pop(); // 일단 pop을 하고 pop을 한 이후 top값이랑 비교
            if(printer.top()==prior) // 중요도가 가장 높은 경우
            {
                cnt ++; // 출력 순서를 증가시킨다. 
                printer.pop();
                if(idx == m) // 이 친구의 초기 인덱스가 찾고자 하는 m 인덱스라면 
                {
                    cout << cnt << "\n"; 
                    break;
                }
            }
             else 
                 q.push({idx,prior}); // 아니면 큐에 다시 넣음 (뒤로 들어감)
        }
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    int j;
    cin >> j;
    
    int left = 1;
    int right = M;
    int move = 0; // 이동거리
    
    for(int i=0; i< j; i++){
        int apple;
        cin >> apple;
        //apple로 사과가 그때그때 어디 떨어지는지 입력받는다. 
        
       //사과가 현재 바구니 왼쪽으로 떨어지는 경우
        if(apple < left){
            int dist = left - apple; // 만약에 왼쪽이 4였는데 사과가 2 위치에 떨어진다고 하면 2만큼 이동해야 됨. 
            move += dist; // 이동거리 축적 
            left -= dist; // 왼쪽 이동
            right -= dist; // 오른쪽 이동 
        }
        else if (apple > right){
            int dist = apple - right;
            move+= dist;
            left += dist;
            right += dist;
        }
        // 사과가 바구니 안에 떨어지면 이동 없음
    }
    
    cout << move << endl;
}
#include <bits/stdc++.h>
using namespace std;

int paper[128][128];  // 최대 128 x 128 입력 가능
int white = 0;         // 0(흰색) 카운트
int blue = 0;          // 1(파란색) 카운트

// 분할 정복 함수
void divide(int x, int y, int size) {
    int color = paper[x][y]; // 처음 기준이 되는 색
    bool same = true; // flag 역할 

    // 현재 구역이 모두 같은 색인지 확인
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (paper[i][j] != color) { // 기준 색과 다르면
                same = false; 
                break;
            }
        }
        if (!same) break; // i for문도 탈출
    }

    // 같은 색이면 카운트하고 종료
    if (same) { 
        if (color == 0) white++;
        else blue++;
        return;
    }

    // 아니면 4등분해서 재귀 호출
    int half = size / 2;
    divide(x, y, half);                         
    divide(x, y + half, half);                  
    divide(x + half, y, half);                  
    divide(x + half, y + half, half);          
}

int main() {
    int N;
    cin >> N;

    // 입력 받기
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> paper[i][j];

    divide(0, 0, N);  // 전체 색종이 영역에서 시작

    cout << white << '\n' << blue << '\n';
    return 0;
}
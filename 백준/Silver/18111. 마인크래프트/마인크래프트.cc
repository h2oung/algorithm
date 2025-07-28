#include <bits/stdc++.h>
using namespace std;

int main() {
    int land[501][501];
    int min_time = INT_MAX;
    int hei = 0;
    int N, M, B;
    cin >> N >> M >> B;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++) {
            cin >> land[i][j];
        }
    }

    for (int h = 0; h <= 256; h++) {
        int remove = 0;
        int stack = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {  
                if (land[i][j] > h)
                    remove += land[i][j] - h;
                else if (land[i][j] < h) 
                    stack += h - land[i][j];
            }
        }

        if (remove + B >= stack) {
            int time = remove * 2 + stack;

            if (time < min_time || (time == min_time && h > hei)) {
                min_time = time;
                hei = h;
            }
        }
    }

    cout << min_time << ' ' << hei << '\n';
}

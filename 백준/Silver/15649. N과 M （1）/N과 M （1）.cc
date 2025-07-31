#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
bool visited[10];

void dfs(int depth) {
    if(depth == M) { // M만큼 다 채워지면 
        for(int i =0; i< M; i++) {
            cout << arr[i] << " "; // 수열 출력 
        } cout << "\n";
    }
    for (int i=1; i<=N; i++){
        if(!visited[i]){
            visited[i]=true;
            arr[depth]=i;
            dfs(depth+1);
            visited[i]=false; // 백트래킹해서 
        }
    }
}

int main() {
    cin >> N >> M;
    dfs(0);
}
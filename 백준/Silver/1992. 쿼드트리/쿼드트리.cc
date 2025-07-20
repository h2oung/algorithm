#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;     
int n; 
string s;   
char a[101][101];
string quard(int y, int x, int size){
    if(size == 1) return string(1, a[y][x]); // quard 반환 타입이 string이기 때문에, 문자 하나도 문자열로 반환해야 한다. 
    char b = a[y][x]; 
    string ret = "";  
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){ 
            if(b != a[i][j]){  // b를 기준으로 하나라도 다르면 4분할로 재귀 호출
                ret += '(';
                ret += quard(y, x, size / 2);  // 왼쪽 위
                ret += quard(y, x + size / 2, size / 2); // 오른쪽 위
                ret += quard(y + size / 2, x, size / 2); // 왼쪽 아래
                ret += quard(y + size / 2, x + size / 2, size / 2); // 오른쪽 아래
                ret += ')';
                return ret;  
            }
        } 
    }
    return string(1, a[y][x]);  // 모두 같은 문자였다면 그 문자를 문자열로 만들어서 반환
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> s; 
        for(int j = 0; j < n; j++){
            a[i][j] = s[j]; // 문자열로 입력된 영상 데이터를 2차원 배열로 저장하는 과정
        }
    }
    cout << quard(0, 0, n) << '\n'; 
	return 0; 
}
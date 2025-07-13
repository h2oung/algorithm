#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c;

ll go (ll a, ll b) {
	if(b==1) return a%c ; // 재귀함수는 기저 사례부터 만들기, 지수가 1이면 바로 나머지값 반환
    ll ret = go(a, b / 2); 
    ret = (ret * ret ) %c; 
    if (b%2) ret = (ret*a) %c;  // ret값이 홀수면 추가적으로 a를 곱해주고 나머지값을 다시 구함. 
    return ret;
} 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> a >> b >> c ;
  cout << go(a,b) << "\n";
  return 0;
}
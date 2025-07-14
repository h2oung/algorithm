#include<bits/stdc++.h>
using namespace std;  

int n;
int main(){ 
	while(scanf("%d", &n) != EOF){
		int cnt = 1, ret = 1; 
        // cnt는 나머지 추적 용도, ret는 문제에서 구하라고 하는 자리수
		while(true){
			if(cnt % n == 0){ 
				printf("%d\n", ret);
				break;
			}else{
				cnt = (cnt * 10) + 1; 
				cnt %= n; 
				ret++;
			}
		} 
	}  
	return 0;
}
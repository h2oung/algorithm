#include <bits/stdc++.h>
using namespace std;  
string s; 
int vowel_cnt, consonant_cnt;

bool isVowel(int idx){ // 모음을 체크하는 함수
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main () { 
	while(true){
		cin >> s; 
		if(s == "end") break; // 마지막 테스트 케이스 명시적으로 end라고 주어졌음. 
		vowel_cnt = consonant_cnt = 0; // 초기화 
		bool flag = 0;
		bool is_include_v = 0;
		int prev = -1; 
		for(int i = 0; i < s.size(); i++){ // 문자열을 한 글자씩 순회
			int idx = s[i]; 
			if(isVowel(idx)) vowel_cnt++, consonant_cnt = 0, is_include_v = 1;
			else consonant_cnt++, vowel_cnt = 0;
			if(consonant_cnt == 3 || vowel_cnt == 3) flag = 1; // 모음이나 자음이 연속으로 3개가 오면 flag 처리
			if(i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o')){ // i가 1이상, 즉 두번째 문자부터 
				flag  = 1;  //
			} 
			prev = idx; // prev는 이전 문자를 저장하는 문자임 
		}  
		if(is_include_v == 0) flag = 1; // 모음을 반드시 하나 포함하여야 한다. 
		if(flag) cout << "<" << s << ">" << " is not acceptable.\n"; // 만약 flag값이 1이면
		else cout << "<" << s << ">" << " is acceptable.\n";
	} 
	return 0;
}
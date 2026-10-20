#include <string>
#include <vector>

using namespace std;

string vowels="AEIOU";
int cnt;
int answer;

void dfs(string s, string target){
    if(!s.empty()) cnt++;
    
    if(s==target) answer=cnt;
    
    if(s.size()==5) return;
    
    for(int i=0; i<5; i++){
        dfs(s+vowels[i], target);
    }
}
int solution(string word) {
    cnt = 0;
    answer = 0;
    
    dfs("", word);
    
    return answer;
}
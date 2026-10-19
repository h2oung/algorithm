#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    // 1. 각 수포자의 반복 패턴
    vector<int> a={1, 2, 3, 4, 5};
    vector<int> b={2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> c={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int score[3]={0,0,0};
    
    // 2. 점수 계산
    for(int i=0; i<answers.size(); i++){
        if(answers[i]==a[i%5]) score[0]++;
        if(answers[i]==b[i%8]) score[1]++;
        if(answers[i]==c[i%10]) score[2]++;
    }
    
    // 3. 최댓값 구하기
    int wmx=0;
    
    for(int max : score){
        if(max>wmx) wmx=max;
    }
    // 이거 너무 길게 쓰긴 했는데 그냥 int wmx=max(score[0], score[1], score[2]) 해도 됨
    
    for (int j = 0; j < 3; j++) {
        if(score[j]==wmx) answer.push_back(j + 1);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
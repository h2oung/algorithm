#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    set<int> k;
    
    for(int i=0; i< nums.size(); i++){
          k.insert(nums[i]);
    }
    
    if(k.size()> (nums.size()/2)) answer=nums.size()/2;
    else answer=k.size();
    
    return answer;
    
}
// 최대한 다양한 포켓몬 N/2

// 종류 갯수를 리턴하는 것

// 종류 갯수가 전체 nums/2보다 크다면 전체 nums/2
// 같거나 작으면 종류갯수
    
// 반복되는건 set에 가둠
    
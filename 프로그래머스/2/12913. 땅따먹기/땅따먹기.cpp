#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > land)
{
    int result=0; 
    
    vector<vector<int>> dp(land.size(), vector<int> (land[0].size(), 0));
    for(int p=0; p<land[0].size(); p++){
        dp[0][p]=land[0][p];
    }
    
    for (int k=1; k<land.size(); k++){
        for(int j=0; j<4; j++){
            int maxVal=0;
            for(int p=0; p<4; p++){
                if(p==j) continue;
                maxVal= max(maxVal, dp[k-1][p]);
            }
            dp[k][j]=land[k][j]+maxVal;
        }
    }
    
     for(int j=0; j<4; j++){
         result= max(result, dp[land.size()-1][j]);
     }
    
    return result;
}
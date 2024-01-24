/*
Unique paths:
Top-down approach
I will move from m-1,n-1 to 0,0.
I will move from up and left , so that sum of top and left will be my result.
*/

class Solution {
public:
    int fun(int i,int j,vector<vector<int>>&dp)
    {
        if(i==0 and j==0) return 1;
        if(i<0 or j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
       
        int up=fun(i-1,j,dp);
        int bottom=fun(i,j-1,dp);

        return dp[i][j]=up+bottom;
    }
    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(n-1,m-1,dp);
    }
};

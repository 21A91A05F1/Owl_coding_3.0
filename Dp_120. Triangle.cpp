class Solution {
public:
    int fun(int i,int j,vector<vector<int>>&triangle,vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==triangle.size()-1) return triangle[i][j];
        

        int one=fun(i+1,j,triangle,dp);
        int two=fun(i+1,j+1,triangle,dp);
        

        return dp[i][j]=min(one,two)+triangle[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
      // we will move from 0 to n-1 since the input taken is of different work. it doesn't works when we mve from n-1 to 0.
        return fun(0,0,triangle,dp);
    }
};

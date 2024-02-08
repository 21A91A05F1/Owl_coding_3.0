class Solution {
public:
    int fun(int n,vector<int>&dp)
    {
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            int p=i*i;
            ans=min(ans,1+fun(n-p,dp));
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return fun(n,dp);
    }
};

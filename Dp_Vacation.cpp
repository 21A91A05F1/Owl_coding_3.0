int fun(int i,int j,int n,vector<vector<int>> &points,vector<vector<int>> &dp)
{
    if(i==n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    for(int k=0;k<3;k++)
    {
        if(k!=j)
        {
            ans=max(ans,fun(i+1,k,n,points,dp));
        }
    }
    return dp[i][j]=points[i][j]+ans;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int ans=0;
    vector<vector<int>>dp(n,vector<int>(3,-1));
    for(int i=0;i<3;i++)
    {
        ans=max(ans,fun(0,i,n,points,dp));
    }
    return ans;
}

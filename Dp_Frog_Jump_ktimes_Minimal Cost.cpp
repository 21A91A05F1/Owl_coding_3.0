int fun(int ind,int n,int k,vector<int> &height,vector<int>&dp)
{
    if(ind==n-1) return 0;
    if(ind>=n) return 1e9;
    int min_steps=1e9;
    if(dp[ind]!=-1) return dp[ind];
    int pick=1e9;
    for(int i=1;i<=k;i++)
    {
        if(ind+i<n)
        {
            pick=abs(height[ind]-height[ind+i])+fun(ind+i,n,k,height,dp);
            min_steps=min(min_steps,pick);
        }
    }
    return dp[ind]=min_steps;
}
int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    vector<int>dp(n+1,-1);
    return fun(0,n,k,height,dp);
}
/*
Recursion
int fun(int ind,int n,int k,vector<int> &height)
{
    if(ind==n-1) return 0;
    if(ind>=n) return 1e9;
    int min_steps=1e9;
    int pick=1e9;
    for(int i=1;i<=k;i++)
    {
        if(ind+i<n)
        {
            pick=abs(height[ind]-height[ind+i])+fun(ind+i,n,k,height);
            min_steps=min(min_steps,pick);
        }
    }
    return min_steps;
}
int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    //vector<int>dp(n+1,-1);
    return fun(0,n,k,height);
}

*/

#include <bits/stdc++.h> 
int fun(int i,int j1,int j2,int r,int c,vector<vector<int>> &grid,vector<vector<vector<int>>>&dp)
{
    if(i>=r or j1<0 or j2<0 or j1>=r or j2>=c) return 0;

    if(i==r-1)
    {
        if(j1==j2) return grid[i][j1];
        else grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
    int maxi=INT_MIN;
    for(int dj1=-1;dj1<=1;dj1++)
    {
        for(int dj2=-1;dj2<=1;dj2++)
        {
            int val=0;
            if(j1==j2)
            {
                val=grid[i][j1]+fun(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
            }
            else
            {
                val=grid[i][j1]+grid[i][j2]+fun(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
            }
            maxi=max(maxi,val);
        }
    }
    return dp[i][j1][j2]=maxi;

}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(r,vector<int>(c,-1)));
    return fun(0,0,c-1,r,c,grid,dp);
}

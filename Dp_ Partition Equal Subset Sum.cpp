#include<bits/stdc++.h>
int fun(int ind,vector<int>&arr,int k,vector<vector<int>>&dp)
{
	if(k<0) return 0;
	if(ind<0) 
	{
		if(k==0) return 1;
		return 0;
	}
	if(k==0) return 1;
	if(dp[ind][k]!=-1) return dp[ind][k];
	int pick=fun(ind-1,arr,k-arr[ind],dp);
	int not_pick=fun(ind-1,arr,k,dp);

	return dp[ind][k]=pick || not_pick;
}
bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int s=accumulate(arr.begin(),arr.end(),0);
	
	if(s%2==1) return false;
	int k=s/2;
	vector<vector<int>>dp(n,vector<int>(k+1,-1));
	if(fun(n-1,arr,k,dp)) return true;
	return false;
}

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        // Complete the function
        unordered_map<int,int>mpp;
        int s=0,maxi=0;
        for(int i=0;i<N;i++)
        {
            s+=A[i];
            if(s==k)
            {
                maxi=max(maxi,i+1);
            }
            
            if(mpp.find(s-k)!=mpp.end())
            {
                maxi=max(maxi,i-mpp[s-k]);
            }
            
            if(mpp.find(s)==mpp.end())
            {
                mpp[s]=i;
            }
        }
        return maxi;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends

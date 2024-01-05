//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        // code here
        int onecnt=0;
        int ans=0;
        for(int i=0;i<32;i++)
        {
            onecnt=0;
            for(int j=0;j<N;j++)
            {
                if(arr[j]&(1<<i)) onecnt++;
            }
            if(onecnt%3!=0)
            {
                //cout<<i;
                ans=ans|(1<<i);
            }
        }
        return ans;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
/*
Input:
10
[1,2,1,3,2,1,2,5,5,5]
write the binaries of the number 
1 --> 0 0 1 
2 --> 
*/
// } Driver Code Ends

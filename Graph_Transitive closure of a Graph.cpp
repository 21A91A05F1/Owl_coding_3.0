//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    void dfs(int node,vector<int> adj[],vector<int>&temp)
    {
        temp[node]=1;
        for(auto it:adj[node])
        {
            if(temp[it]==0)
            {
                dfs(it,adj,temp);
            }
        }
    }
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        // code here
        int n=graph.size();
        int m=graph[0].size();
        
        vector<int>adj[n];
        vector<vector<int>>res;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(graph[i][j]==1)
                {
                    adj[i].push_back(j);
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            vector<int>temp(n,0);
            dfs(i,adj,temp);
            res.push_back(temp);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends

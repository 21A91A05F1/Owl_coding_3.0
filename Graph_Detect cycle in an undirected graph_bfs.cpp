//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect_cycle(int src,vector<int> adj[],vector<int>&vis)
    {
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty())
        {
            int Node=q.front().first;
            int parent=q.front().second;
            
            q.pop();
            for(auto it:adj[Node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push({it,Node});
                }
                // if someone visited and did not come from it , then it's a cycle.
                else if(parent!=it)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        //for components we use a for loop , to traverse to all the components.
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detect_cycle(i,adj,vis)==true) return true;   
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends

//Detect cycle in an undirected graph
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool detect_cycle(int Node,int Parent,vector<int> adj[],vector<int>&vis)
    {
        vis[Node]=1;
        for(auto it:adj[Node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                if(detect_cycle(it,Node,adj,vis)==true) return true;
            }
            else if(Parent!=it)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        //for componrnts we use a for loop , to traverse to all the components.
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detect_cycle(i,-1,adj,vis)==true) return true;   
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

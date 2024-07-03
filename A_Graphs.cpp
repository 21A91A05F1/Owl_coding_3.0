===================================================Graph traversals===============================================================
  ============Adjacent List 
  vector<vector<int>> adjList(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // this statement will be removed in case of directed graph
    }

============Dfs(depth first search)
   void dfs(int node,vector<int>adj[],int vis[],vector<int>&res)
    {
        vis[node]=1;
        res.push_back(node);
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis,res);
            }
        }
    }
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        // Code here
        int vis[n]={0};
        int start=0;
        vector<int>res;
        dfs(start,adj,vis,res);
        return res;
    }
=====================Bfs(breadth first search)
   vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        queue<int>q;
        vector<int>res;
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int Node=q.front();
            res.push_back(Node);
            q.pop();
             for(auto it:adj[Node])
             {
                 if(vis[it]==0)
                 {
                     q.push(it);
                     vis[it]=1;
                     
                 }
             }
            
        }
        return res;
    }
=======================No. of components in graph
int components(vector<vector<int>>& isConnected) {
        vector<int>vis(v,0);
        int c=0;
        for(int i=0;i<v;i++)
        {
                if(vis[i]==0)
                {
                    vis[i]=1;
                    dfs(i,vis,adj);
                    c++;
                }
            
        }
        return c;

}
====================Good components in grpah (No.of connected components in grpah)
int numberOfGoodComponents(int n, vector<pair<int, int>>& edges) {
    // Step 1: Create the graph using adjacency list representation
    vector<vector<int>> adjList(n + 1);
    for (const auto& edge : edges) {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first);
    }

    vector<bool> visited(n + 1, false);
    int goodComponentsCount = 0;

    // Step 2: Find all connected components
    for (int node = 1; node <= n; ++node) {
        if (!visited[node]) {
            vector<int> component;
            dfs(node, adjList, visited, component);

            // Step 3: Check if all vertices in the component have the same degree
            unordered_set<int> degrees;
            for (int vertex : component) {
                degrees.insert(adjList[vertex].size());
            }

            if (degrees.size() == 1) {
                ++goodComponentsCount;
            }
        }
    }

    return goodComponentsCount;
}
=================================Topo sort ( u-> v ) u should come first then v , order should be maintained=============
  #include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> kahnToposort(int n, vector<vector<int>>& adjList) {
    vector<int> inDegree(n, 0);
    for (int u = 0; u < n; ++u) {
        for (int v : adjList[u]) {
            ++inDegree[v];
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int v : adjList[u]) {
            if (--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (topoOrder.size() != n) {
        throw runtime_error("Graph is not a DAG");
    }

    return topoOrder;
}

============================toposort dfs
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited, stack<int>& topoStack) {
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited, topoStack);
        }
    }

    topoStack.push(node);
}

vector<int> dfsToposort(int n, vector<vector<int>>& adjList) {
    vector<bool> visited(n, false);
    stack<int> topoStack;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, adjList, visited, topoStack);
        }
    }

    vector<int> topoOrder;
    while (!topoStack.empty()) {
        topoOrder.push_back(topoStack.top());
        topoStack.pop();
    }

    return topoOrder;
}
======================================================Cycle detection================================
  

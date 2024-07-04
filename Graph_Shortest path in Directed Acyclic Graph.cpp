 void toposort(int node,  vector<pair<int,int>>adj[],stack<int>&st,int vis[])
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            int v=it.first;
            if(!vis[v])
            {
                toposort(v,adj,st,vis);
            }
        }
        st.push(node);
    }
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[n];
        
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        //find the toposort
        stack<int>st;
        int vis[n]={0};
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            
            {
                toposort(i,adj,st,vis);
            }
        }
        
        //distances
        vector<int>dist(n);
        for(int i=0;i<n;i++) dist[i]=1e9;
        dist[0]=0;
        
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            
            for(auto it:adj[node])
            {
                int v=it.first;
                int wt=it.second;
                if(dist[node]+wt<dist[v])
                {
                    dist[v]=dist[node]+wt;
                }
            }
        }
        vector<int>res(n,-1);
        for(int i=0;i<n;i++)
        {
            if(dist[i]!=1e9) res[i]=dist[i];
        }
        return res;
    }
};

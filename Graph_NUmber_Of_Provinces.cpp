class Solution {
public:
    void dfs(int Node,vector<int>&vis,vector<int> adjl[])
    {
            for(auto it:adjl[Node])
            {
                if(vis[it]==0) 
                {
                    vis[it]=1;
                    dfs(it,vis,adjl);
                }
            }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<int>adj[v];
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(isConnected[i][j]==1 and i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
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
};

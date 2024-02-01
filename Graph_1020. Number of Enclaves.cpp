class Solution {
public:
    void dfs(int i,int j,int n,int m,int drow[],int dcol[],vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        vis[i][j]=1;
        for(int p=0;p<4;p++)
        {
            int nrow=i+drow[p];
            int ncol=j+dcol[p];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0 and grid[nrow][ncol]==1)
            {
                vis[nrow][ncol]=1;
                dfs(nrow,ncol,n,m,drow,dcol,grid,vis);
            }
        }


    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(i==0 or i==n-1 or j==0 or j==m-1)
               {
                     if(grid[i][j]==1)
                {
                    vis[i][j]=1;
                    dfs(i,j,n,m,drow,dcol,grid,vis);
                }
               }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 and grid[i][j]==1) cnt++;
                if(vis[i][j]==0)
                {
                    grid[i][j]=1;
                }
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        int res=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' and vis[i][j]==0)
                {
                    q.push({i,j});
                     while(!q.empty())
                     {
                        vis[i][j]=1;

                        int row=q.front().first;
                        int col=q.front().second;

                        q.pop();
                        int c=0;
                       for(int k=0;k<4;k++)
                       {
                            int nrow=row+drow[k];
                            int ncol=col+dcol[k];
                            //if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==1) c++;
                            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]=='0' and vis[nrow][ncol]==0) c++;
                            else if(nrow<0 or nrow>=n or ncol<0 or ncol>=m) c++;
                            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]=='1' and vis[nrow][ncol]==0)
                            {
                                q.push({nrow,ncol});
                                vis[nrow][ncol]=1;
                            }
                            
                           
                       }   
                       // if(c==4) res++;
                    }
                    if(q.empty()) res++;
                }
                
            }
        }
        return res;
    }
};

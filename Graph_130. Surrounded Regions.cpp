class Solution {
public:
    void dfs(int i,int j,int n,int m,int drow[],int dcol[],vector<vector<char>>&board,vector<vector<int>>&vis)
    {
        if(board[i][j]=='X') return;
        vis[i][j]=1;
        for(int p=0;p<4;p++)
        {
            int nrow=i+drow[p];
            int ncol=j+dcol[p];

            if(nrow<n and ncol<m and nrow>=0 and ncol>=0 and vis[nrow][ncol]==0 and board[nrow][ncol]!='X')
            {
                vis[nrow][ncol]=1;
                dfs(nrow,ncol,n,m,drow,dcol,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
       int n=board.size();
       int m=board[0].size();
       
       vector<vector<int>>vis(n,vector<int>(m,0));
       int drow[]={-1,0,1,0};
       int dcol[]={0,1,0,-1};

       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(i==0 or j==0 or i==n-1 or j==m-1)
               {
                   if(board[i][j]=='O')
                   {
                       dfs(i,j,n,m,drow,dcol,board,vis);
                   }
               }
           }
       }
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(vis[i][j]==0)
               {
                   board[i][j]='X';
               }
           }
       }
    }
};

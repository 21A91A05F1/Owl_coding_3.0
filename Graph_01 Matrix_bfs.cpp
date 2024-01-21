class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dummy(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    dummy[i][j]=0;
                }
            }
        }

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int cnt=q.front().second;
            q.pop();
            cout<<"hi";
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];

                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0)
                {
                    
                    q.push({{nrow,ncol},cnt+1});
                    vis[nrow][ncol]=1;
                    dummy[nrow][ncol]=cnt+1;
                }
            }
        }
        return dummy;

    }
};

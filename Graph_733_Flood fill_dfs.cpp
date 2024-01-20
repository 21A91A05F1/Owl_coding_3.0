class Solution {
public:
    void dfs(int n,int m,int drow[],int dcol[],int sr,int sc,int color,vector<vector<int>>& image,vector<vector<int>>& dummy,int k)
    {
        
        dummy[sr][sc]=color;
        for(int i=0;i<4;i++)
        {
            int nrow=sr+drow[i];
            int ncol=sc+dcol[i];
             if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and image[nrow][ncol]==k and dummy[nrow][ncol]!=color)
                {
                    dfs(n,m,drow,dcol,nrow,ncol,color,image,dummy,k);
                }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        /*dfs
        */
        int n=image.size();
        int m=image[0].size();
        int k=image[sr][sc];
        vector<vector<int>>dummy=image;

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        dfs(n,m,drow,dcol,sr,sc,color,image,dummy,k);

        return dummy;
    }
};

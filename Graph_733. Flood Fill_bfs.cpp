class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //bfs..
        /*
            I have considered a copy of the given matrix.
            we will push the image[sr][sc] to the queue.
            we will make the neighbours of that particular node as new color.
            To check the neighbours of one particular node , i will consider drow and dcol , i will check top, bottom,left and right directions .
            if that particular node is already visited and marked as new color , then I don't need to visit it again..
        */
        int n=image.size();
        int m=image[0].size();
        
        queue<pair<int,int>>q;
        int vis[n][m];
        vector<vector<int>>dummy=image;
        q.push({sr,sc});
        dummy[sr][sc]=color;
        int k=image[sr][sc];

        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;

            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+row[i];
                int ncol=c+col[i];

                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and dummy[nrow][ncol]==k and dummy[nrow][ncol]!=color)
                {
                    q.push({nrow,ncol});
                    dummy[nrow][ncol]=color;
                }
            }
        }
        return dummy;
    }
};

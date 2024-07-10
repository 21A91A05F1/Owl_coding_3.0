Recursion
==========
   int  fun(int days,int last,vector<vector<int>>&points)
   {
       if(days==0)
       {
           int maxi=0;
           for(int i=0;i<=2;i++)
           {
               if(i!=last)
               {
                   maxi=max(maxi,points[0][i]);
               }
           }
           return maxi;
       }
       int maxi=0;
       for(int i=0;i<=2;i++)
       {
           if(i!=last)
           {
               int point=points[days][i]+fun(days-1,i,points);
               maxi=max(maxi,point);
           }
       }
       return maxi;
   }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here

        return fun(n-1,3,points);
    
    }
============2d dp
 int  fun(int days,int last,vector<vector<int>>&points,vector<vector<int>>&dp)
   {
       if(dp[days][last]!=-1) return dp[days][last];
       if(days==0)
       {
           int maxi=0;
           for(int i=0;i<=2;i++)
           {
               if(i!=last)
               {
                   maxi=max(maxi,points[0][i]);
               }
           }
           return maxi;
       }
       int maxi=0;
       for(int i=0;i<=2;i++)
       {
           if(i!=last)
           {
               int point=points[days][i]+fun(days-1,i,points,dp);
               maxi=max(maxi,point);
           }
       }
       return dp[days][last]=maxi;
   }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return fun(n-1,3,points,dp);
    
    }

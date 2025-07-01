class Solution {
public:
int minFallingPathSum(vector<vector<int>>& matrix,int i,int j,int n,vector<vector<int>>& dp) {
     
     if(j>=n || j<0)
          return INT_MAX;

        if(i==n-1)
        {
            return matrix[n-1][j];
        }

        if(dp[i][j]!=-1)
          return dp[i][j];


        int a= minFallingPathSum(matrix,i+1,j-1,n,dp);
        int b=minFallingPathSum(matrix,i+1,j,n,dp);
        int c=minFallingPathSum(matrix,i+1,j+1,n,dp);

        return dp[i][j]=matrix[i][j]+min({a,b,c});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
       int mn=INT_MAX;
    //    vector<vector<int>> dp(n,vector<int>(n,-1));
        // for(int j=0;j<n;j++)
        // {
        //    mn=min(mn,minFallingPathSum(matrix,0,j,n,dp));
        // }
        // return mn;

        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int j=0;j<n;j++)
        {
            dp[n-1][j]=matrix[n-1][j];
        }

        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int a=INT_MAX,b=INT_MAX,c=INT_MAX;
                if(j-1>=0)
                 a=dp[i+1][j-1];
                if(j+1<n)
                 b=dp[i+1][j+1];
                c=dp[i+1][j];
                dp[i][j]=matrix[i][j]+min({a,b,c});  
            }
        }
        for(int j=0;j<n;j++)
          mn=min(dp[0][j],mn);

          return mn;
    }
};
*******************************************************************************************************************************************************************************************
int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
       int mn=INT_MAX;
    //    vector<vector<int>> dp(n,vector<int>(n,-1));
        // for(int j=0;j<n;j++)
        // {
        //    mn=min(mn,minFallingPathSum(matrix,0,j,n,dp));
        // }
        // return mn;

        // vector<vector<int>> dp(n,vector<int>(n,0));
        vector<int> front(n,0),curr(n,0);

        for(int j=0;j<n;j++)
        {
            front[j]=matrix[n-1][j];
        }

        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int a=INT_MAX,b=INT_MAX,c=INT_MAX;
                if(j-1>=0)
                 a=front[j-1];
                if(j+1<n)
                 b=front[j+1];
                c=front[j];
                curr[j]=matrix[i][j]+min({a,b,c});  
            }
            front=curr;
        }
        for(int j=0;j<n;j++)
          mn=min(front[j],mn);

          return mn;
    }

class Solution {
public:
    int uniquePaths(vector<vector<int>>& obstacleGrid,int m, int n,int i,int j,vector<vector<int>>& dp) {
        if(i>=m|| j>=n)
         return 0;

        if(obstacleGrid[i][j]==1)
          return 0; 

        if(i==m-1 && j==n-1)
          return 1;

           if(dp[i][j]!=-1)
           return dp[i][j];

       
         int a= uniquePaths(obstacleGrid,m,n,i+1,j,dp);
         int b= uniquePaths(obstacleGrid,m,n,i,j+1,dp);
         return dp[i][j]= a+b;   
    }
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m=obstacleGrid.size();
    //     int n=obstacleGrid[0].size();
    //    vector<vector<int>> dp(m,vector<int>(n,-1));
    //      return uniquePaths(obstacleGrid,m,n,0,0,dp);   
    // }
     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
     {
         int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        long long** dp = new long long*[m];
    for (int i = 0; i < m; i++) {
        dp[i] = new long long[n];
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

        if(obstacleGrid[m-1][n-1]==1 ||obstacleGrid[0][0]==1)
          return 0;

        dp[m-1][n-1]=1;

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1)
                  continue;
                 
                long long a=0,b=0; 
                if(i+1<m  && obstacleGrid[i+1][j]!=1)
                 a=  dp[i+1][j];
                if(j+1<n && obstacleGrid[i][j+1]!=1)
                 b= dp[i][j+1];

                 dp[i][j]=a+b; 
            }
        }

        return (int)dp[0][0];
     }
};

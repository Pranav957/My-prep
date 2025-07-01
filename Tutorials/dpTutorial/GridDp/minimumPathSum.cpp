class Solution {
public:
int helper(vector<vector<int>>& grid,int i,int j,int m,int n,int** dp)
{
     if( i>=m  || j>=n)
      return INT_MAX;

   if(i==m-1 && j==n-1)
    return grid[i][j];

    if(dp[i][j]!=-1)
      return dp[i][j];
  
  int a=helper(grid,i,j+1,m,n,dp);
  int b=helper(grid,i+1,j,m,n,dp);

  return dp[i][j]=min(a,b)+grid[i][j];

}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // int **dp=new int*[m];
        // for(int i=0;i<m;i++)
        // {
        //     dp[i]=new int[n];
        //     for(int j=0;j<n;j++)
        //      dp[i][j]=-1;
        // }
        // return helper(grid,0,0,m,n,dp);
        vector<vector<int>> dp(m,vector<int>(n));
        dp[m-1][n-1]=grid[m-1][n-1];

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                 if(i==m-1 && j==n-1)
                  continue;

                 int a=INT_MAX;
                 int b=INT_MAX;
                 if(j+1<n)
                  a=dp[i][j+1];
                 if(i+1<m)
                   b=dp[i+1][j];             
                 dp[i][j]=min(a,b)+grid[i][j]; 
            }
        }
        return dp[0][0];

        
    }
};

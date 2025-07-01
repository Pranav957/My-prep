class Solution {
public:
    int uniquePaths(int m, int n,int i,int j,vector<vector<int>>& dp) {
        if(i>=m|| j>=n)
         return 0;

         if(dp[i][j]!=-1)
           return dp[i][j];

        if(i==m-1 && j==n-1)
          return 1;

       
         int a= uniquePaths(m,n,i+1,j,dp);
         int b= uniquePaths(m,n,i,j+1,dp);
         return dp[i][j]= a+b;   
    }

     int uniquePaths(int m, int n)
     {
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        //  return uniquePaths(m,n,0,0,dp);
        int** dp=new int*[m];
        for(int i=0;i<m;i++)
        {
            dp[i]=new int[n];
        }

        dp[m-1][n-1]=1;

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1)
                  continue;
                 
                int a=0,b=0; 
                if(i+1<m)
                 a=  dp[i+1][j];
                if(j+1<n)
                 b= dp[i][j+1];

                 dp[i][j]=a+b; 
            }
        }

        return dp[0][0];
     }
};

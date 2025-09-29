class Solution {
  public:
  int matrixMultiplication(vector<int> &arr,int i,int j, vector<vector<int>>&dp) {
        // code here
        if(i==j)          //i>=j
         return 0;
         
         int mini=INT_MAX;
         
         if(dp[i][j]!=-1)
          return dp[i][j];
         
         for(int k=i;k<j;k++)
         {
             int ans=arr[i-1]*arr[k]*arr[j]+
             matrixMultiplication(arr,i,k,dp)+matrixMultiplication(arr,k+1,j,dp);
             mini=min(mini,ans);
         }
         
         return dp[i][j]=mini;
       
    }
 

    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
   return matrixMultiplication(arr,1,n-1,dp);
    }
};
******************************************************************************
int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//   return matrixMultiplication(arr,1,n-1,dp);
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
         dp[i][i]=0;       //as 0 no need to write;
         
         for(int i=n-1;i>=1;i--)
         {
             for(int j=i+1;j<=n-1;j++) // as j always to the right of i
             {    
                 int mini=INT_MAX;
                   for(int k=i;k<j;k++)
                     {
                         int ans=arr[i-1]*arr[k]*arr[j]+
                         dp[i][k]+dp[k+1][j];
                         mini=min(mini,ans);
                     }
                 dp[i][j]=mini;     
             }
         }
         return dp[1][n-1]; //opposite to top down
    }

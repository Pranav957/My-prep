    class Solution {
public:

    int isSubsetSum(vector<int>& arr, int sum, int n,int** dp) {
        
        if (sum == 0)
            return 1;
        if (n == 0)
            return 0;
            
            if(dp[n][sum]!=-1)
             return dp[n][sum];

        if (arr[n - 1] <= sum) {
            int a = isSubsetSum(arr, sum - arr[n - 1], n - 1,dp);
            int b = isSubsetSum(arr, sum, n - 1,dp);
            return dp[n][sum]= a || b;
        }
        return dp[n][sum]= isSubsetSum(arr, sum, n - 1,dp);
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        // int** dp=new int*[n+1];
        // for(int i=0;i<=n;i++)
        // {
        //     dp[i]=new int[sum+1];
        //     for(int j=0;j<sum+1;j++)
        //       dp[i][j]=-1;
        // }
        // return isSubsetSum(arr, sum, arr.size(),dp);
        // vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        vector<int> prev(sum+1,0);
        vector<int> curr(sum+1,0);
        
        prev[0]=1;
        
        // for(int j=0;j<sum+1;j++)
        //   prev[j]=0;
          
        // for(int i=0;i<n+1;i++)
        //   dp[i][0]=1;
          
          for(int i=1;i<n+1;i++)
          {
               curr[0] = 1;
              for(int j=1;j<sum+1;j++)
              {
                  int a=0;
                  if(arr[i-1]<=j)
                    a=prev[j-arr[i-1]];
                
                  int b=prev[j];
                  
                  curr[j]=a||b;
                   
              }
              prev=curr;
          }
          
          return prev[sum];
    }
};

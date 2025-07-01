class Solution {
public:
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
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        for(int j=0;j<sum+1;j++)
          dp[0][j]=0;
          
        for(int i=0;i<n+1;i++)
          dp[i][0]=1;
          
          for(int i=1;i<n+1;i++)
          {
              for(int j=1;j<sum+1;j++)
              {
                  int a=false;
                  if(arr[i-1]<=j)
                    a=dp[i-1][j-arr[i-1]];
                
                  int b=dp[i-1][j];
                  
                  dp[i][j]=a||b;
                   
              }
          }
          
          return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
       int sum=0;
       for(int i=0;i<nums.size();i++)
         sum+=nums[i];

       if(sum%2!=0)
         return false;
        return isSubsetSum(nums,sum/2);    
    }
};

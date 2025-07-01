class Solution {
public:
    int findMax(vector<int>& nums, int n,vector<int> dp)
  {
     if(n<=0)
     return 0;

     if(dp[n]!=-1)
      return dp[n];

    int a= nums[n-1]+findMax(nums,n-2,dp);
    int b= findMax(nums,n-1,dp);

    return dp[n]=max(a,b);

  }
    int rob(vector<int>& nums) {
        int n=nums.size();
    //     vector<int> dp(n+1,-1);
    //    return findMax(nums,n,dp);

     vector<int> dp(n+1);

     dp[0]=0;
     dp[1]=nums[0];

     for(int i=2;i<=n;i++)
     {
        dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
     }
     return dp[n];

    }
};

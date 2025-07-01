class Solution {
public:
   int helper(vector<int>& nums)
   {
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
    int rob(vector<int>& nums) {
        if(nums.size()==1)
         return nums[0];
        vector<int> temp1=nums;
        temp1.pop_back();
        vector<int> temp2=nums;
        temp2[0]=0;
        return max(helper(temp1),helper(temp2));
    }
};

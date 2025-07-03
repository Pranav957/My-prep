class Solution {
public:
    int lengthOfLIS(vector<int>& nums,int prev,int idx,int n,vector<vector<int>>& dp) { //LIS starting from ith index with previous x
        if(idx==n)
         return 0;
        
        if(dp[prev+1][idx]!=-1)
         return dp[prev+1][idx];

         int b=0;
         if(prev==-1 || nums[idx]>nums[prev])
          b= 1+lengthOfLIS(nums,idx,idx+1,n,dp);

          int a= lengthOfLIS(nums,prev,idx+1,n,dp);

       return dp[prev+1][idx]= max(a,b);    
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
       return lengthOfLIS(nums,-1,0,nums.size(),dp);
    }
};

***************************************************************************************************************

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {  // LIS ending at ith index;
        int n=nums.size();
        vector<int> ans(n,1);
     
       for(int i=1;i<n;i++)
       {
         ans[i]=1;
         for(int j=i-1;j>=0;j--)
         {
            if(nums[j]<nums[i])
            {
                int poss=ans[j]+1;
                ans[i]=max(ans[i],poss);
            }
         }
       }

       int res=0;
       for(int i=0;i<n;i++)
        {
            if(ans[i]>res)
             res=ans[i];
        }
    return res;

    }
};

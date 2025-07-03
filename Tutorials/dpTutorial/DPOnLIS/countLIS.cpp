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
       //  vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
       // return lengthOfLIS(nums,-1,0,nums.size(),dp);

        vector<vector<int>> dp(n+1,vector<int>(n+1,0)); // if base case 0 no initialization required
     for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= -1; j--) {
            int b = 0;
            if (j == -1 || nums[i] > nums[j]) {
                b = 1 + dp[i+1][i+1];
            }
            int a = dp[i+1][j+1];

            dp[i][j+1] = max(a, b);
        }
    }
   

       return dp[0][0];
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

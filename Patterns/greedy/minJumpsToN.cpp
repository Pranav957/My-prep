class Solution {
public:
     int jump(vector<int>& nums,int idx,vector<int>& dp) 
     {
       if(idx>=nums.size()-1)
        return 0;

        if(dp[idx]!=-1)
          return dp[idx];

        int mn=INT_MAX-1;

       for(int i=1;i<=nums[idx];i++)
       {
         if(idx+i<nums.size())
           mn=min(mn,jump(nums,idx+i,dp));
       }
       return dp[idx]=mn+1;  
     }
    int jump(vector<int>& nums) {
        int n=nums.size();
        // vector<int> dp(n,-1);
        // return jump(nums,0,dp);
         vector<int> dp(n,0);
         for(int i=n-2;i>=0;i--)
         {
            int mn=INT_MAX-1;
            for(int j=1;j<=nums[i];j++)
            {
                if(i+j<n)
                  mn=min(mn,dp[i+j]);
            }
            dp[i]=mn+1;
         }
         return dp[0];
    }
};

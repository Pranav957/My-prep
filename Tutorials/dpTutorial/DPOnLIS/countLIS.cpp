class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
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

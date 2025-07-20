    int longestOnes(vector<int>& nums, int k) {
        int longest=0;
        int left=0;
        int zeros=0;
        for(int r=0;r<nums.size();r++)
        {
          if(nums[r]==0)
          {
             zeros++;
          }
          if(zeros<=k)
          {
             longest=max(longest,r-left+1);
          }
          else
            {
                while(nums[left]!=0)
                 left++;
               left++;
               zeros--;  
            }
        }
        return longest;
    }
};

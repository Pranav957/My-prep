int maxSubArray(vector<int>& nums) {
        int currentsum=nums[0];
        int maxSum=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            currentsum=max(nums[i],nums[i]+currentsum);
            maxSum=max(currentsum, maxSum);
        }
        return maxSum;
    }

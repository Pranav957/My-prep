double findMaxAverage(vector<int>& nums, int k) {
        int maxSum=INT_MIN;
        for(int i=0;i<=nums.size()-k;i++)
        {
           int sum=0;
           for(int j=i;j<i+k;j++)
           {
             sum+=nums[j];
           }
           maxSum=max(sum,maxSum);
        }
        return double(maxSum)/k;
    }

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
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
          double findMaxAverage(vector<int>& nums, int k) {
        int maxSum=INT_MIN;
        int sum=0;
       for(int i=0;i<k;i++)
         sum+=nums[i];

         maxSum=sum;

        for(int i=k;i<nums.size();i++)
        {
            sum+=nums[i];
            sum-=nums[i-k];
            if(sum>maxSum)
             maxSum=sum; 
        } 
        return double(maxSum)/k;
    }

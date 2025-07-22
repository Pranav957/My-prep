class Solution {
public:
  int numSubarrays(vector<int>& nums, int goal) {
        if(goal==-1)
           return 0;
        int ans=0;
        int n=nums.size();
        int left=0,r=0;
        int sum=0;
        while(r<n)
        {
           sum+=nums[r]%2;
           
           while(sum>goal)
            { 
                sum-=nums[left]%2;
                left++;
            }

           ans+=r-left+1 ;
            
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numSubarrays(nums,k)-numSubarrays(nums,k-1);
    }
};

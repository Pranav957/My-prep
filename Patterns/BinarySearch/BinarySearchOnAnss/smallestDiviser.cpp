class Solution {
public:
    int getDivisionSum(vector<int>&nums, int dev)
    {
        int sum=0;
       for(int i=0;i<nums.size();i++)
       {
        sum+=(nums[i]+dev-1)/dev;
       }
       return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
       int maxi=*max_element(nums.begin(),nums.end()); 
       int low=1, high=maxi;
       int ans=-1;
       while(low<=high)
       {
          int mid=(low+high)/2;
          if(getDivisionSum(nums,mid)<=threshold)
            {
                high=mid-1;
                ans=mid;
            }
          else
             low=mid+1;
       }
       return ans;
    }
};
************************************************************************************************************************8
  class Solution {
public:
    int getDivisionSum(vector<int>&nums, int dev)
    {
        int sum=0;
       for(int i=0;i<nums.size();i++)
       {
        sum+=(nums[i]+dev-1)/dev;
       }
       return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
       int maxi=*max_element(nums.begin(),nums.end()); 

       for(int i=1;i<=maxi;i++)
       {
          if(getDivisionSum(nums,i)<=threshold)
            return i;
       }
       return -1;
    }
};

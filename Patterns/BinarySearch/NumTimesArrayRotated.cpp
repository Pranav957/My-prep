class Solution {
  public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int ans=INT_MAX;
        int indx=-1;
        while(low<=high)
        {
            if(nums[low]<=nums[high])
            {
            if(nums[low]<ans)
                {
                    indx=low;
                    ans=nums[low];
                }
                break;
            }

            int mid=(low+high)/2;


            if(nums[low]<=nums[mid])
            {
                if(nums[low]<ans)
                {
                    indx=low;
                    ans=nums[low];
                }
    
                low=mid+1;
            }
            else
            {
                 if(ans>nums[mid])
                {
                    indx=mid;
                    ans=nums[mid];
                }
                 high=mid-1;
            }
        }
        return indx;
    }
    int findKRotation(vector<int> &arr) {
        // Code Here
        return findMin(arr);
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=(low+high)/2;

            if(nums[low]<=nums[mid])
            {
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else
            {
                ans=min(ans,nums[mid]);
                 high=mid-1;
            }
        }
        return ans;
    }
};
************************************************************************************************
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int ans=INT_MAX;
        while(low<=high)
        {
           if(nums[low]<=nums[high])  //slight obtimization
           {
            ans=min(nums[low],ans);
            break;
           }

            int mid=(low+high)/2;


            if(nums[low]<=nums[mid])
            {
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else
            {
                ans=min(ans,nums[mid]);
                 high=mid-1;
            }
        }
        return ans;
    }
};

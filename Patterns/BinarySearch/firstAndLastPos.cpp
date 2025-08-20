class Solution {
public:
    int getFirst(vector<int>& nums, int target,int low,int high) 
        {
            int first=-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(target<nums[mid])
                 high=mid-1;
                else if(target>nums[mid])
                 low=mid+1;
                else
                 {
                    first=mid;
                    high=mid-1;
                 } 
                  
            }
            return first;
        }
        int getSecond(vector<int>& nums, int target,int low,int high) 
        {
            int second=-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(target<nums[mid])
                 high=mid-1;
                else if(target>nums[mid])
                 low=mid+1;
                else
                 {
                    second=mid;
                   low=mid+1;
                 } 
                  
            }
            return second;
        }
    vector<int> searchRange(vector<int>& nums, int target) {

          int first=getFirst(nums,target,0,nums.size()-1);
             if(first==-1) return {-1,-1};
          int second=getSecond(nums,target,0,nums.size()-1);
          return {first,second};
    }
};
***********************************************************************************************************************
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a=lower_bound(nums.begin(),nums.end(),target)-nums.begin();

        if(a== nums.size() || nums[a]!=target)
          return {-1,-1};

          int b= upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        return {a,b-1};  
    }
};

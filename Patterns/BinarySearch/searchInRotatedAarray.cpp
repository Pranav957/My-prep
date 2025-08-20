class Solution {
public:
   int helper(vector<int>& nums,int left,int right,int target)
   {
      if(left>right)
       return -1;

       int mid=(left+right)/2;

       if(nums[mid]==target)
         return mid;

       if(nums[left]<=nums[mid])
       {
          if(target>=nums[left] && target<=nums[mid])
             return helper(nums,left,mid-1,target);
          else
           return helper(nums,mid+1,right,target);
       }
       else
       {
        if(target>=nums[mid] && target<=nums[right])
            return helper(nums,mid+1,right,target);
          else
            return helper(nums,left,mid-1,target);
       }
   }
    int search(vector<int>& nums, int target) {
        return helper(nums,0,nums.size()-1,target);
    }
};
***********************************************************
class Solution {
public:
   int helper(vector<int>& nums,int left,int right,int target)
   {
      while(left<=right)
      {
        int mid=(left+right)/2;

        if(nums[mid]==target)
         return mid;

        if(nums[left]<=nums[mid])
        {
           if(target>=nums[left] && target<nums[mid])
              right=mid-1;
           else
            left=mid+1;

        }else
        {
            if(target>nums[mid] && target<=nums[right])
              left=mid+1;
           else
           right=mid-1; 
        } 
      }
      return -1;
       
   }
    int search(vector<int>& nums, int target) {
        return helper(nums,0,nums.size()-1,target);
    }
};

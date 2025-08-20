class Solution {
public:
     bool helper(vector<int>& nums,int left,int right,int target) //O(n/2) shrinking might required
   {
      while(left<=right)
      {
        int mid=(left+right)/2;

        if(nums[mid]==target)
         return true;

          if(nums[left]==nums[mid] && nums[mid]==nums[right])
        {
            left=left+1;
            right=right-1;
           continue;
        }  

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
      return false;
   }
      
    bool search(vector<int>& nums, int target) {
        return helper(nums,0,nums.size()-1,target);
    }
};
*******************************************************************************************************************************8
     class Solution {
public:
   bool helper(vector<int>& nums,int left,int right,int target)
   {
      if(left>right)
       return false;

       int mid=(left+right)/2;

       if(nums[mid]==target)
         return true;

        if(nums[left]==nums[mid] && nums[mid]==nums[right])
        {
          return helper(nums,left+1,right-1,target);
        }  

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
    bool search(vector<int>& nums, int target) {
        return helper(nums,0,nums.size()-1,target);
    }
};

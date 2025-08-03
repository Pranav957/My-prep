class Solution {
public:
   void subsets(vector<int>& nums,vector<int> v,int i,vector<vector<int>>& ans)
   {
       if(i==nums.size())
       {
         ans.push_back(v);
         return;
       } 
       subsets(nums,v,i+1,ans);
       v.push_back(nums[i]);
       subsets(nums,v,i+1,ans); 
   }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>v;
        subsets(nums,v,0,ans);
        return ans;
    }
};
*********************************************************************************************************
class Solution {
public:
   void subsets(vector<int>& nums,vector<int> v,int i,vector<vector<int>>& ans)
   {
       if(i==nums.size())
       {
         ans.push_back(v);
         return;
       } 
        v.push_back(nums[i]);
       subsets(nums,v,i+1,ans);
       v.pop_back();
       subsets(nums,v,i+1,ans); 
   }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>v;
        subsets(nums,v,0,ans);
        return ans;
    }
};

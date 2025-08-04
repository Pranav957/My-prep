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
*************************************************************************************************************
vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        // vector<int>v;
        // subsets(nums,v,0,ans);
        // return ans;
        int n=nums.size();
        for(int num=0;num<pow(2,n);num++)//  for(int num=0;num<(1<<n);num++)
        {
            vector<int> v;
            for(int i=0;i<n;i++)
            {
              if((num&(1<<i))!=0)  // if((num&(1<<i))
                v.push_back(nums[i]);
            }
            ans.push_back(v);
        }
        return ans;
    }
*************************************************************************************************
UNIQUESUBSETS

class Solution {
public:
  void subsetsWithDup(vector<int>& nums,int i,vector<int> v,vector<vector<int>>& ans) {
     if(i==nums.size())
     {
         ans.push_back(v);
         return;
     }
    int j=i+1;
     while(j<nums.size() && nums[j]==nums[i])
      j++;
    
    subsetsWithDup(nums,j,v,ans);
    v.push_back(nums[i]);
    subsetsWithDup(nums,i+1,v,ans);

  }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        subsetsWithDup(nums,0,v,ans);
        return ans;
    }
};

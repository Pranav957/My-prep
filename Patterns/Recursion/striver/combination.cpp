class Solution {
public:
   void combinationSum(vector<int>& candidates, int target,vector<int> v,int i,vector<vector<int>> &ans) {
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        if(i==candidates.size())
          return ;

         if(candidates[i]<=target)
         {
            combinationSum(candidates,target,v,i+1,ans);
            v.push_back(candidates[i]);
            combinationSum(candidates,target-candidates[i],v,i,ans);
         }
         else
            combinationSum(candidates,target,v,i+1,ans);

   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>v;
        combinationSum(candidates,target,v,0,ans);
        return ans;
    }
};


**************************************************************************************************************************************************************
class Solution {
public:
     void combinationSum(vector<int>& candidates, int target,vector<int> v,int ind,vector<vector<int>> &ans) {
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        if(ind==candidates.size())
          return ;
       int x=-1;
       for(int i=ind;i<candidates.size();i++)
       {
          if(candidates[i]==x) continue;
          if(candidates[i]>target)
           break;
          
            v.push_back(candidates[i]);
            combinationSum(candidates,target-candidates[i],v,i+1,ans);
            v.pop_back();
            x=candidates[i];
          
       }   

   }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        combinationSum(candidates,target,v,0,ans);
        return ans;
    }
};

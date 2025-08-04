class Solution {
public:
  void combinationSum3(int k, int n,int ind,int x,vector<int>v,vector<vector<int>>& ans)
  {
    if(n==0)
    {
        if(ind==k)
         ans.push_back(v);
       return;  
    }
    
    for(int i=x;i<10;i++)
    {
       if(i>n) continue;
       v.push_back(i);
      combinationSum3(k,n-i,ind+1,i+1,v,ans); 
      v.pop_back();   
    }
  }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        combinationSum3(k,n,0,1,v,ans);
        return ans;
    }
};

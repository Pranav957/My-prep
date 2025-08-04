class Solution {
public:
   bool check(string s,int i,int j)
   {
      while(i<j)
      {
        if(s[i]!=s[j])
         return false;
         i++;
         j--;
      }
      return true;
   }
    void partition(string s,vector<string>v,vector<vector<string>> &ans) {
        if(s.empty())
         {
            ans.push_back(v);
            return;
         }

         for(int i=0;i<s.length();i++)
         {
            if(check(s,0,i))
            {
                v.push_back(s.substr(0,i-0+1));
                partition(s.substr(i+1),v,ans);
                v.pop_back();
            }
         }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        partition(s,v,ans);
        return ans;
    }
};

class Solution {
public:
    void letterCombinations(string digits,string v,vector<string>& ans,unordered_map<int,string> mp){

        if(digits.empty())
        {
          if(!v.empty())  
          ans.push_back(v);
          return;
        }
        string str=mp[digits[0]-'0'];
       
      for(int i=0;i<str.length();i++)
      {
         letterCombinations(digits.substr(1),v+str[i],ans,mp);
      }

    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        vector<string> ans;
        letterCombinations(digits,"",ans,mp);
        return ans;
    }
};

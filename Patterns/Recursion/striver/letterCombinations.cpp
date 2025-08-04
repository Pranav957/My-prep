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
***********************************************************************************************************************************
class Solution {
    unordered_map<int,string> mp;
public:
   Solution()
   {
    mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
   }
    vector<string> letterCombinations1(string digits){
       if(digits.empty())
        {  
            return {};
        }

        vector<string> res=letterCombinations1(digits.substr(1));
        vector<string>ans;

        string str=mp[digits[0]-'0'];
        if(res.empty())res.push_back("");

        for (int i = 0; i < str.length(); i++) {
            for (int j = 0; j < res.size(); j++) {
                ans.push_back(str[i] + res[j]);
            }
        }   

      return ans;
        
    }
    vector<string> letterCombinations(string digits) {

        return letterCombinations1(digits);
    }
};
***********************************************************************************************************************************************************
class Solution {
    unordered_map<int,string> mp;
public:
   Solution()
   {
    mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
   }
    vector<string> letterCombinations1(string digits){
       if(digits.empty())
        {
            vector<string> v;
            v.push_back("");
            return v;
        }

        vector<string> res=letterCombinations1(digits.substr(1));
        int k=res.size();

        string str=mp[digits[0]-'0'];

        for(int i=1;i<str.length();i++)
        {
            for(int j=0;j<k;j++)
            {
              res.push_back(str[i]+res[j]);
            }
        }

         for(int j=0;j<k;j++)
            {
              res[j]=str[0]+res[j];
            }        

      return res;
        
    }
    vector<string> letterCombinations(string digits) {
         if(digits.empty())
          return {};
        return letterCombinations1(digits);
    }
};

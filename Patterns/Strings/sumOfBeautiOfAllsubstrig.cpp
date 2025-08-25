class Solution {
public:
    int beautySum(string s) {
         int beautiSum=0;
        for(int i=0;i<s.length();i++)
        {
            unordered_map<char,int> mp;
            for(int j=i;j<s.length();j++)
            {
              mp[s[j]]++;

              int maxi=INT_MIN;
              int mini=INT_MAX;

              for( auto each:mp)
              {
                maxi=max(maxi,each.second);
                mini=min(mini,each.second);
              }
              beautiSum+=maxi-mini;
            }
        }
        return beautiSum;
    }
};

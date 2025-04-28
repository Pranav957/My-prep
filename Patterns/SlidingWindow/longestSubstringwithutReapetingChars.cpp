bool isUnique(string s,int i,int j)
{
    unordered_map<char,int> mp;
    for(int k=i;k<=j;k++)
       mp[s[k]]++;

      for(auto it=mp.begin();it!=mp.end();it++)
      {
        if(it->second>1)
         return false;
      } 
      return true;
}
    int lengthOfLongestSubstring(string s) {
        int maxLength=0;
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                if(isUnique(s,i,j))
                 maxLength=max(maxLength,j-i+1);
            }
        }
        return maxLength;
    }

class Solution {
public:
    string minWindow(string s, string t) {
        //  unordered_map<char,int> mp;
          int n=s.length();
          string ans="";
          int minLength=INT_MAX;

         for(int i=0;i<n;i++)
         { 
            string str="";
            int cnt=0;
            int mp[256]={0};
             for(int i=0;i<t.length();i++)
            mp[t[i]]++;
            for(int j=i;j<n;j++)
            {
                mp[s[j]]--;
                str+=s[j];
                if(mp[s[j]]>=0)
                 cnt++;
                if(cnt==t.length())
                 break; 
            }
            if(cnt==t.length()&& !str.empty() && str.length()<minLength)
            {
                ans=str;
                minLength=str.length();
            }
         } 
         return ans;
    }
};
******************************************************************************************8
    class Solution {
public:
    string minWindow(string s, string t) {
        //  unordered_map<char,int> mp;
          int n=s.length();
          int minLength=INT_MAX;
          int startIndx=-1;

         for(int i=0;i<n;i++)
         { 
            int cnt=0;
            int mp[256]={0};
            for(int i=0;i<t.length();i++)
               mp[t[i]]++;
            for(int j=i;j<n;j++)
            {
                if (mp[s[j]] > 0) 
                cnt++;
                mp[s[j]]--;
                if(cnt==t.length())
                {
                   if(j-i+1<minLength)
                   {
                    minLength=j-i+1;
                    startIndx=i;
                   } 
                    break;
                } 
            }
         } 
         return (startIndx == -1) ? "" : s.substr(startIndx, minLength);
    }
};

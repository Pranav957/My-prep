class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest=0;
        int n=s.length();
        int left=0;
        int hash[26]={0};
        int mx=0;

        for(int r=0;r<n;r++)
        {
            hash[s[r]-'A']++;
            mx=max(mx,hash[s[r]-'A']);
            if(r-left+1-mx<=k)
            {
                longest=max(longest,r-left+1);
            }
            else
            {
                  hash[s[left]-'A']--;
                left++;
            }

        }
       
        return longest;
    }
};
****************************************************************
class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest=0;
        int n=s.length();
        int left=0;
        int hash[26]={0};
        int mx=0;

        for(int r=0;r<n;r++)
        {
            hash[s[r]-'A']++;
            mx=max(mx,hash[s[r]-'A']);
            if(r-left+1-mx<=k)
            {
                longest=max(longest,r-left+1);
            }
            else
            {    while(r-left+1-mx>k)
                  {
                    hash[s[left]-'A']--;
                left++;
                  }
            }

        }
       
        return longest;
    }
};
******************************************************************************************
class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest=0;
        int n=s.length();
       
        for(int i=0;i<n;i++)
        {
            int mx=0;
             int hash[256]={0};
            for(int j=i;j<n;j++)
            {
               hash[s[j]]++;
               mx=max(hash[s[j]],mx);
               if(j-i+1-mx<=k)
               {
                longest=max(longest,j-i+1);
               }
               else
                break;
            }
        }
        return longest;
    }
};

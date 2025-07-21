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

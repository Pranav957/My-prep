class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n=s.length(),mx=-1;
        unordered_map<char,int> mp;
        int left=0;
        for(int r=0;r<n;r++)
        {
            mp[s[r]]++;
            if(mp.size()==k)
            {
                mx=max(mx,r-left+1);
            }
            while(mp.size()>k)
            {
                mp[s[left]]--;
                if(mp[s[left]]==0)
                 mp.erase(s[left]);
                 
                 left++;
            }
            
        }
        return mx;
        
        
    }
};

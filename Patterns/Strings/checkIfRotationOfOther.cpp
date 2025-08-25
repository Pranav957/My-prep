class Solution {
public:
    bool rotateString(string s, string goal) {
        // for(int i=0;i<s.length();i++)
        // {
        //     rotate(s.begin(),s.begin()+1,s.end());
        //     if(s==goal)return true;
        // }
        //  return false;
        if(s.length()!=goal.length())return false;
        if((s+s).find(goal)!= string:: npos)
         return true;
        return false; 
    }
   
};
*********************************************************ANAGRAM**********************************8
    class Solution {
public:
     bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false; // lengths must match

        unordered_map<char,int> mp;

        for (char c : s) {
            mp[c]++;
        }

        for (char c : t) {
            mp[c]--;
            if (mp[c] == 0) mp.erase(c);
        }

        return mp.empty();
    }
};
*************************************************************MAX Depth*********************************************
    class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int cnt=0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
              cnt++;
            else if(s[i]==')')
             cnt--;

             maxi=max(maxi,cnt);  
        }
        return maxi;
    }
};
*******************************************************************************************************************************
class Solution {
public:
    int romanToInt(string s) {
         unordered_map<char,int> val = {
            {'I',1}, {'V',5}, {'X',10}, {'L',50},
            {'C',100}, {'D',500}, {'M',1000}
        };
        
        int n = s.size();
        int ans = 0;
        
        for(int i=0;i<n;i++){
            if(i+1<n && val[s[i]] < val[s[i+1]]) {
                ans -= val[s[i]]; 
            } else {
                ans += val[s[i]]; 
            }
        }
        return ans;
    }
};

class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastSeen[3]={-1,-1,-1};
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            lastSeen[s[i]-'a']=i;
            if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1)
                cnt+= 1+min({lastSeen[0],lastSeen[1],lastSeen[2]});  

        }
        return cnt;
    }
};
******************************************************
class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_set<char> st;
        int cnt=0;
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                 st.insert(s[j]);
                 if(st.size()==3)
                 {
                    cnt+=s.length()-j;
                    break;
                 } 
            }
            st.clear();
        }
        return cnt;
    }
};

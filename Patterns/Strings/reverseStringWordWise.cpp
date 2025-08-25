class Solution {
public:
    string reverseWords(string s) {
     string str = "";
        string ans = "";
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                str += s[i];
            } else {
                if (!str.empty()) {  // only if we have a valid word
                    if (!ans.empty())
                        ans = str + " " + ans;
                    else
                        ans = str;
                    str = "";
                }
            }
        }
        
        if (!str.empty()) {
            if (!ans.empty())
                ans = str + " " + ans;
            else
                ans = str;
        }
        
        return ans;
    }

};
**********************************************************************************************************************************************************
class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
       string str="";
       for(int i=0;i<s.length();i++)
       {
         if(s[i]!=' ')
           str+=s[i];
          else
           {
            if(!str.empty())
              st.push(str);
            str="";
           } 
       }
       if(!str.empty())
        st.push(str);
       string ans="";
       while(st.size()!=1)
       {
         ans+=st.top()+" ";
         st.pop();
       }  

       ans+=st.top();
       st.pop();
       return ans;   

    }
};

// User function Template for C++

class Solution {
  public:
    string preToPost(string exp) {
        int i=exp.length()-1;
        stack<string> st;
        while(i>=0)
        {
           if((exp[i]>='A' && exp[i]<='Z')|| (exp[i]>='a' && exp[i]<='z')||(exp[i]>='0' && exp[i]<='9'))
            st.push(string(1,exp[i]));
           else
           {
               string t1=st.top();st.pop();
               string t2=st.top();st.pop();
               string ans=t1+t2+exp[i];
               st.push(ans);
           }
           i--;
        }
        return st.top();
    }
};

class Solution {
  public:
   int priority(char x)
   {
       if(x=='^')return 3;
       if(x=='*'|| x=='/') return 2;
       if(x=='+'|| x=='-')return 1;
        return -1;
   }
    string infixToPostfix(string& s) {
        // code here
        int i=0;
        stack<char> st;
        string ans="";
        
        while(i<s.length())
        {
            if((s[i]>='A' && s[i]<='Z')|| (s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9'))
            {
                ans+=s[i];
            }else if(s[i]=='(')
             st.push('(');
            else if(s[i]==')')
            {
                while(!st.empty() && st.top()!='(')
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while(!st.empty() && priority(s[i])<=priority(st.top()))
                {
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};

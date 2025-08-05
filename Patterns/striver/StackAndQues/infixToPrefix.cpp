class Solution {
  public:
    string reverse(string s,int i,int j) {
        // code here
        while(i<j)
        {
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }
        
       return s; 
    }
    int priority(char x)
   {
       if(x=='^')return 3;
       if(x=='*'|| x=='/') return 2;
       if(x=='+'|| x=='-')return 1;
        return -1;
   }
    string infixToPrefix(string& s) {
        // code here
        s=reverse(s,0,s.length()-1);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
             s[i]=')';
             else if(s[i]==')')
              s[i]='(';
        }
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
               if(!st.empty()) st.pop();
            }
            else
            {
                while(!st.empty() && s[i]!='^' && priority(s[i])<=priority(st.top()))
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
        return reverse(ans,0,ans.length()-1);
    }
};
****************************************************************************************************************************************************88
  class Solution {
  public:
    string reverse(string s,int i,int j) {
        // code here
        while(i<j)
        {
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }
        
       return s; 
    }
    int priority(char x)
   {
       if(x=='^')return 3;
       if(x=='*'|| x=='/') return 2;
       if(x=='+'|| x=='-')return 1;
        return -1;
   }
    string infixToPrefix(string& s) {
        // code here
        s=reverse(s,0,s.length()-1);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
             s[i]=')';
             else if(s[i]==')')
              s[i]='(';
        }
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
               if(!st.empty()) st.pop();
            }
            else
            {
                if(s[i]=='^')
                {
                   while(!st.empty()  && priority(s[i])<=priority(st.top()))
                    {
                        ans+=st.top();
                        st.pop();
                    } 
                }
                else
                {
                    while(!st.empty()  && priority(s[i])<priority(st.top()))
                    {
                        ans+=st.top();
                        st.pop();
                    } 
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
        return reverse(ans,0,ans.length()-1);
    }
};

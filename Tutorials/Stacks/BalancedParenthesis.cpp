#include<stack>
bool isBalanced(string expression) 
{
    // Write your code here
    stack<char> st;
   for(int i=0;i<expression.length();i++)
   {
        if(expression[i]=='(')
           st.push('(');
         else if (expression[i]==')')
          {
              if(!st.empty() && st.top()=='(')
              st.pop();
               else
                      return false ;
          }  
   }
   if(!st.empty())
   {
       return false;
   }
   return true;
}
 

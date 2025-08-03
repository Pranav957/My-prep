
class Solution {
  public:
    void reverse(stack<int> &st) {
        // code here
        if(st.empty())
         return;
        
        int temp=st.top();
        st.pop();
        reverse(st);
        stack<int> st2;
        while(!st.empty())
        {
            st2.push(st.top());
            st.pop();
        }
        st.push(temp);
        while(!st2.empty())
        {
            st.push(st2.top());
            st2.pop();
        }
    }
};

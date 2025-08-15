// Min stack can also be implemented in O(1) using stack<pair<int,int>> where first element is stack element and second is minimum found uptill now
class MinStack {
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        while(!st.empty())
         st.pop();
        mini=INT_MAX;
    }
    
    void push(int val) {
        if(st.empty())
         {
            mini=val;
            st.push(val);
         }
         else if(val>mini)
          st.push(val);
         else 
         {
            st.push((long long)2*val-mini);
            mini=val;
         } 
    }
    
    void pop() {
        if(!st.empty())
        {
            if(st.top()<mini)
            {
                mini=2*mini-st.top();
            }
            st.pop();
        }
    }
    
    int top() {
        if(st.empty())
         return -1;

         if(st.top()<mini)
          return mini;
         else
          return st.top();  

    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

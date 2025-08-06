void nextSmaller(vector<int>& arr) {
        //  code here
     stack<int> st;
     for(int i=0;i<arr.size();i++)
     {
         while(!st.empty() && arr[i]<arr[st.top()])
         {
            arr[st.top()]=arr[i];
            st.pop();
         }
         st.push(i);
     }
     while(!st.empty())
        {
            arr[st.top()]=-1;
           st.pop();
        }   
    }

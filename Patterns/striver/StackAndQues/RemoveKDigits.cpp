class Solution {
public:
    string removeKdigits(string nums, int k) { //get rid of larger ones and keep smaller ones at start

        // if(k==nums.length())
        //   return "0";
        stack<char> st;
        st.push(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            while(!st.empty() && nums[i]<st.top() && k>0)
            {
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }
        
        while(k>0 && !st.empty()) //edgecase3 if still k >0 means for example  "123456"
       {
         st.pop();
         k--;
       } 

       string str="";
       while(!st.empty())
       {
        str+=st.top();
        st.pop();
       }

       reverse(str.begin(),str.end());  // cpp consider string as part of stl;
       int i=0;
       while(!str.empty() && str[0]=='0') //edgecase 2 if "00200"
        {
            str=str.substr(1);
            i++;
        } 

        if(str=="")   //egdecase1 if k==nums.size()
          return "0";

     return str;
         
    }
};

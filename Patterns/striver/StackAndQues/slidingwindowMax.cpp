class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<=n-k;i++)
        {
           int maxi=nums[i];
           for(int j=i;j<i+k;j++)
           {
             maxi=max(maxi,nums[j]);
           }
           ans.push_back(maxi);
        }
        return ans;
    }
};
******************************************************************************************************************
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans;
        deque<int> st;
        for(int i=0;i<n;i++)
        {
          if(!st.empty() && st.front()<=i-k)
            st.pop_front();

          while(!st.empty() && nums[st.back()]<=nums[i]) 
            st.pop_back(); 

            st.push_back(i);

           if(i>=k-1) ans.push_back(nums[st.front()]); 
        }
        return ans;
    }
};

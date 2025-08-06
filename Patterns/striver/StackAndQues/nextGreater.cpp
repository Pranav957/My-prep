class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int x=*max_element(nums2.begin(),nums2.end());
        vector<int> mp(x+1,-1);
        stack<int> st;
        for(int i=0;i<nums2.size();i++)
        {
          while(!st.empty()&& nums2[i]>st.top())
          {
            mp[st.top()]=nums2[i];
            st.pop();
          }
          st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};

***************************************************************************************************
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int x=*max_element(nums2.begin(),nums2.end());
        vector<int> mp(x+1,-1);
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--)
        {
          while(!st.empty()&& nums2[i]>=st.top())
          {
            st.pop();
          }
          if(st.empty()) mp[nums2[i]]=-1;
          else mp[nums2[i]]=st.top();

          st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};

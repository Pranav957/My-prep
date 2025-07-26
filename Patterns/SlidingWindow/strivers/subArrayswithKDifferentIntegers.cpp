class Solution {
public:
    int subarraysWithKDistinct1(vector<int>& nums, int k) {
        int cnt=0,n=nums.size();
        unordered_map<int,int> mp;
        int left=0;
       for(int r=0;r<n;r++)
       {
          mp[nums[r]]++;
        
          while(mp.size()>k)
          {
            mp[nums[left]]--;
            if(mp[nums[left]]==0)
              mp.erase(nums[left]);
            left++;
          } 
          cnt+=r-left+1;
       }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithKDistinct1(nums,k)-subarraysWithKDistinct1(nums,k-1);
    }
};
*****************************************************************************************************************************************************
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int cnt=0,n=nums.size();
        unordered_set<int> st;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
               st.insert(nums[j]);
               if(st.size()==k)
                cnt+=1;
               if(st.size()>k)
                 break; 
            }
            st.clear();
        }
        return cnt;
    }
};

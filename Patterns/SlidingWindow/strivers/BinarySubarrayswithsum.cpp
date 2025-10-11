class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
              sum+=nums[j];
              if(sum==goal)
              {
                ans++;
              } 
            }
        }
        return ans;
    }
};
****************************************************************
class Solution {
public:
    int numSubarrays(vector<int>& nums, int goal) {
        if(goal==-1)
           return 0;
        int ans=0;
        int n=nums.size();
        int left=0,r=0;
        int sum=0;
        while(r<n)
        {
           sum+=nums[r];
           
           while(sum>goal)
            { 
                sum-=nums[left];
                left++;
            }

           ans+=r-left+1 ;
            
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      return numSubarrays(nums,goal)-numSubarrays(nums,goal-1);
    }
};
*********************************************************
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int sum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
          sum+=nums[i];
          if(mp.count(sum-goal)>0)
          {
            cnt+=mp[sum-goal];
          }
          mp[sum]++;
        }
        return cnt;
    }
};

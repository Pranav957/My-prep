class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) { // if two sums have same mod then there exists a subarray mutltiple of k
        unordered_map<int,int> mp;
        mp[0]=-1;
       int sum=0;

        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];

             if(k!=0)
              sum%=k;

              if(mp.count(sum)>0)
              {
                int x=i-mp[sum];
                if(x>=2)
                 return true;
              }
              else{
                 mp[sum]=i;
              }

        }
        return false;
    }
};
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<MAXLENGTH<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    class Solution {
public:
     int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum=0;
        int maxlength=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
              sum+=1;
            else
             sum-=1;

             if(mp.find(sum)!=mp.end())
             {
               int length=i-mp[sum];
               maxlength=max(maxlength,length);
             } 
             else
              mp[sum]=i; 
        }
        return maxlength;

    }
};

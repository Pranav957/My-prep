class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int ans;
        map<int,int> mp;
        int x=nums.size()/2;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;   
        }
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]>x)
             return nums[i];
            
        }
      return ans;  
    }
    
};
******************************************************************
class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int ans,maxi=INT_MIN;
        map<int,int> mp;
        int x=nums.size()/2;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;   
        }
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]>maxi)
            {
                maxi=mp[nums[i]];
                ans=nums[i];
            }
            
        }
      return ans;  
    }
    
};
***************************************************************
class Solution {
public:
 //only one element can be there which can be grater than n/2
    int majorityElement(vector<int>& nums) {
         int cnt=0;
         int ele;
         for(int i=0;i<nums.size();i++)
         {
            if(cnt==0)
            {
                cnt=1;
                ele=nums[i];
            }
            else if(ele!=nums[i])
             cnt--;
            else
             cnt++; 
         } 
          int cnt1=0;
         for(int i=0;i<nums.size();i++)
         {
           if(nums[i]==ele)
            cnt1++;
         } 
         if(cnt1>(nums.size()/2))
          return ele;

          return -1;
    }
    
};

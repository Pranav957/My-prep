*********************************************************************
class Solution {
public:
//max 2 elements can be there which are gretaer that n/3
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int x=nums.size()/3;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++; 
            if(mp[nums[i]]==x+1)
             ans.push_back(nums[i])  ;

             if(ans.size()==2)break;
        }
       
       return ans;
    }
};
****************************************************************
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int x=nums.size()/3;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;   
        }
       for(auto ele:mp)
       {
        if(ele.second>x)
          ans.push_back(ele.first);
       }
       return ans;
    }
};
***************************************************************
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int x=nums.size()/3;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;   
        }
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[nums[i]]>x)
             st.insert(nums[i]);
        }
        for(auto it:st)
        {
            ans.push_back(it);
        }
      ********************************************************************
        class Solution {
public:
//max 2 elements can be there which are gretaer that n/3
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int ele1=INT_MIN,ele2=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt1==0 && nums[i]!=ele2)
            {
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1)
            {
                cnt2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1)
             cnt1++;
             else if(nums[i]==ele2)
              cnt2++;
            else
             {
                cnt1--; cnt2--;
             }  
        }
        vector<int> ans;
        int limit=nums.size()/3;
        cnt1=0;
        cnt2=0;
        for(int  i=0;i<nums.size();i++)
        {
            if(nums[i]==ele1)
              cnt1++;
             if(nums[i]==ele2)
             cnt2++;
        }
        if(cnt1>limit)ans.push_back(ele1);
        if(cnt2>limit)ans.push_back(ele2);
        
        return ans;
    }
};
        return ans;
    }
};

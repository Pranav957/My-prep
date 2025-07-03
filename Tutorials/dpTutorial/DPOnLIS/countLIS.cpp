class Solution {
public:
    int lengthOfLIS(vector<int>& nums,int prev,int idx,int n,vector<vector<int>>& dp) { //LIS starting from ith index with previous x
        if(idx==n)
         return 0;
        
        if(dp[prev+1][idx]!=-1)
         return dp[prev+1][idx];

         int b=0;
         if(prev==-1 || nums[idx]>nums[prev])
          b= 1+lengthOfLIS(nums,idx,idx+1,n,dp);

          int a= lengthOfLIS(nums,prev,idx+1,n,dp);

       return dp[prev+1][idx]= max(a,b);    
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
       //  vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
       // return lengthOfLIS(nums,-1,0,nums.size(),dp);

        vector<vector<int>> dp(n+1,vector<int>(n+1,0)); // if base case 0 no initialization required
     for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= -1; j--) {
            int b = 0;
            if (j == -1 || nums[i] > nums[j]) {
                b = 1 + dp[i+1][i+1];
            }
            int a = dp[i+1][j+1];

            dp[i][j+1] = max(a, b);
        }
    }
   

       return dp[0][0];
    }
};
*********************************************************************************
     vector<int> front(n+1,0);
     vector<int> curr(n+1,0);

     for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= -1; j--) {
            int b = 0;
            if (j == -1 || nums[i] > nums[j]) {
                b = 1 + front[i+1];
            }
            int a = front[j+1];

            curr[j+1] = max(a, b);
        }
        front=curr;
    }
   

       return front[-1+1];
        
    }
*****************************************************************************************
     vector<int> front(n+1,0);

     for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= -1; j--) {
            int b = 0;
            if (j == -1 || nums[i] > nums[j]) {
                b = 1 + front[i+1];
            }
            int a = front[j+1];

            front[j+1] = max(a, b);
        }
    }
   
       return front[-1+1];
        
    }

***************************************************************************************************************

     int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
     vector<int> dp(n,1);
     int maxi=1;
     for(int i=0;i<n;i++)
     {
        for(int prev=0;prev<i;prev++)
        {
            if(nums[i]>nums[prev])
             dp[i]=max(dp[i],1+dp[prev]);
        }
        maxi=max(maxi,dp[i]);
     }
     return maxi;
        
    }
*********************************************************************************************************************************

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {  // LIS ending at ith index;
        int n=nums.size();
        vector<int> ans(n,1);
     
       for(int i=1;i<n;i++)
       {
         ans[i]=1;
         for(int j=i-1;j>=0;j--)
         {
            if(nums[j]<nums[i])
            {
                int poss=ans[j]+1;
                ans[i]=max(ans[i],poss);
            }
         }
       }

       int res=0;
       for(int i=0;i<n;i++)
        {
            if(ans[i]>res)
             res=ans[i];
        }
    return res;

    }
};
************************************************************************Binary Search (nlogn)***************************************************************88
    class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>temp.back())
             temp.push_back(nums[i]);
            else
             {
                int idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();//binary Search
                 // *idx=nums[i]
               temp[idx]=nums[i];
             } 
        }
        return temp.size();
    }
};

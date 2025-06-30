class Solution {

  public:
      vector<int> isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        vector<int> prev(sum+1,0);
        vector<int> curr(sum+1,0);
        
        prev[0]=1;
          
          for(int i=1;i<n+1;i++)
          {
               curr[0] = 1;
              for(int j=1;j<sum+1;j++)
              {
                  int a=false;
                  if(arr[i-1]<=j)
                    a=prev[j-arr[i-1]];
                
                  int b=prev[j];
                  
                  curr[j]=a||b;
                   
              }
              prev=curr;
          }
          
          return prev;
    }
        
    int minDifference(vector<int>& nums) {
        int sum=0;
        int n=nums.size();

        for(int i=0;i<n;i++)
          sum+=nums[i];

        vector<int> dp=isSubsetSum(nums,sum/2);


        vector<int> v;
        for(int i=0;i<=sum/2;i++)
        {
            if(dp[i]==true)
              v.push_back(i);
        }

        int mini=INT_MAX;
        for(int i=0;i<v.size();i++)
        { 
            mini=min((sum-2*v[i]),mini);
        }

        return mini;

    }
};

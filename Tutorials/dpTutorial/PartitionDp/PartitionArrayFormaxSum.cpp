class Solution {
public:
  int maxSumAfterPartitioning(vector<int>& arr, int k,int i,int n,vector<int>& dp) {
        if(i==n) return 0;

        if(dp[i]!=-1)
         return dp[i];

        int maxi=INT_MIN;
        int len=0,ans=INT_MIN;
        for(int j=i;j<min(n,i+k);j++)
        {
            len++;
            maxi=max(maxi,arr[j]);
            int cost=(len*maxi)+maxSumAfterPartitioning(arr,k,j+1,n,dp);
            ans=max(cost,ans);
        }
        return dp[i]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        // vector<int> dp(n+1,-1);
    //   return maxSumAfterPartitioning(arr,k,0,n,dp); 
        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--)
        {
            
        int maxi=INT_MIN;
        int len=0,ans=INT_MIN;
        for(int j=i;j<min(n,i+k);j++)
        {
            len++;
            maxi=max(maxi,arr[j]);
            int cost=(len*maxi)+dp[j+1];
            ans=max(cost,ans);
        }
           dp[i]= ans;
        }  
        return dp[0];
    }
};

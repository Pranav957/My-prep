class Solution {
public:
    int coinChange(vector<int>& coins,int n, int amount, vector<vector<int>>& dp) {
    
        if(amount==0)
           return 0;

        if(n==0)
          return INT_MAX-1;

          if(dp[n][amount]!=-1)
            return dp[n][amount];

          if(coins[n-1]<=amount)
          {
             int x=1+coinChange(coins,n,amount-coins[n-1],dp);
             int y= coinChange(coins,n-1,amount,dp);
             return dp[n][amount]=min(x,y);
          } 

         return dp[n][amount]=coinChange(coins,n-1,amount,dp);  
    }

     int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        // int res= coinChange(coins,coins.size(),amount,dp);
        //  return (res == INT_MAX - 1) ? -1 : res;

        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<amount+1;j++)
            {
                if(j==0)
                  dp[i][j]=0;
                else if(i==0)
                  dp[i][j]=INT_MAX-1;   
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<amount+1;j++)
            {
                if(coins[i-1]<=j)
                 dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        int res= dp[n][amount];
       return (res == INT_MAX-1  ) ? -1 : res;
     }

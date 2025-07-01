class Solution {
public:
    int change(int amount, vector<int>& coins,int n,vector<vector<int>> &dp) {
       if(amount==0)
         return 1; 
        if(n==0)
        return 0;

        if(dp[n][amount]!=-1)
          return dp[n][amount];

        if(coins[n-1]<=amount)
        {
            int a= change(amount-coins[n-1],coins,n,dp); 
            int b= change(amount,coins,n-1,dp);
            return dp[n][amount]=a+b;
        } 
        return dp[n][amount]= change(amount,coins,n-1,dp);     
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        //   return change(amount,coins,coins.size(),dp);

          int** dp=new int*[n+1];
          for(int i=0;i<=n;i++)
          {
             dp[i]=new int[amount+1];
          }

          for(int j=0;j<amount+1;j++)
           dp[0][j]=0;

          for(int i=0;i<n+1;i++)
            dp[i][0]=1;

            for(int i=1;i<n+1;i++)
            {
              for(int j=1;j<amount+1;j++)
              {
                  if(coins[i-1]<=j)
                    {
                        int a= dp[i][j-coins[i-1]] ;
                        int b= dp[i-1][j];
                         dp[i][j]=a+b;
                    } 
                   else
                    dp[i][j]= dp[i-1][j]; 
              }
            }
            return dp[n][amount]; 
    }
};

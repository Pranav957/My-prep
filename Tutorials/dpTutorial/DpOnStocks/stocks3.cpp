class Solution {
public:
     int maxProfit(vector<int>& prices,int idx,bool buy,int n,int trans, vector<vector<vector<int>>>& dp) {
        if(idx==n || trans==0)
          return 0;

          if(dp[idx][buy][trans]!=-1)
           return dp[idx][buy][trans];

        if(buy)
        {
            int a= (-prices[idx]+maxProfit(prices,idx+1,false,n,trans,dp)); 
            int b=maxProfit(prices,idx+1,true,n,trans,dp); 
            return dp[idx][buy][trans]=max(a,b);
        } 
        else
        {
            int a= prices[idx]+maxProfit(prices,idx+1,true,n,trans-1,dp); 
            int b=maxProfit(prices,idx+1,false,n,trans,dp); 
             return dp[idx][buy][trans]= max(a,b);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // return maxProfit(prices,0,true,prices.size(),2,dp);
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        //  for(int i=0;i<=n;i++)  //already initialized to 0
        //  {
        //     for(int j=0;j<2;j++)
        //     {
        //         dp[i][j][0]=0;
        //     }
        //  }

        //  for(int j=0;j<2;j++)
        //  {
        //     for(int k=0;k<3;k++)
        //     {
        //         dp[n][j][k]=0;
        //     }
        //  }


         for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 1; k <= 2; k++) {  // skip k == 0
                if (j == 1) {
                    // buy
                    dp[i][j][k] = max(-prices[i] + dp[i + 1][0][k], dp[i + 1][1][k]);
                } else {
                    // sell
                    dp[i][j][k] = max(prices[i] + dp[i + 1][1][k - 1], dp[i + 1][0][k]);
                }
            }
        }
    }
         

         return dp[0][1][2];
    }

};

***************************************************************************************************************************************************************
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> after(2,vector<int>(3,0));
         vector<vector<int>> curr(2,vector<int>(3,0));


         for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 1; k <= 2; k++) {  // skip k == 0
                if (j == 1) {
                    // buy
                    curr[j][k] = max(-prices[i] + after[0][k], after[1][k]);
                } else {
                    // sell
                    curr[j][k] = max(prices[i] + after[1][k - 1], after[0][k]);
                }
            }
        }
        after=curr;
    }
         

         return after[1][2];
    }
**********************************************************************************************************

         for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 1; k <= 2; k++) {  // skip k == 0
                if (j == 1) {
                    // buy
                    after[j][k] = max(-prices[i] + after[0][k], after[1][k]);
                } else {
                    // sell
                    after[j][k] = max(prices[i] + after[1][k - 1], after[0][k]);
                }
            }
        }
    }

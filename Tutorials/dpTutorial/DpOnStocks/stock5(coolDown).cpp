class Solution {
public:
int maxProfit(vector<int>& prices,int idx,bool buy,int n, vector<vector<int>>& dp) {
        if(idx>=n)
         return 0;

         if(dp[idx][buy]!=-1)
          return dp[idx][buy];

        if(buy)
        {
            int a=-prices[idx]+maxProfit(prices,idx+1,false,n,dp);
            int b=maxProfit(prices,idx+1,true,n,dp);
            return dp[idx][buy]= max(a,b);
        } 
        else
        {
            int a=prices[idx]+maxProfit(prices,idx+2,true,n,dp);
            int b=maxProfit(prices,idx+1,false,n,dp);
            return dp[idx][buy]= max(a,b);
        }

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // return maxProfit(prices,0,true,n,dp);

         vector<vector<int>>dp(n+2,vector<int>(2,0));

         for(int i=n-1;i>=0;i--)
         {
            for(int j=0;j<2;j++)
            {
                if(j)
                {
                    int a=-prices[i]+dp[i+1][0];
                    int b=dp[i+1][1];
                    dp[i][j]=max(a,b);
                }
                else
                {
                    int a=prices[i]+dp[i+2][1];
                    int b=dp[i+1][0];
                    dp[i][j]=max(a,b);
                }
            }
         }

         return dp[0][true];
    }
};

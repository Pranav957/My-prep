class Solution {
public:
 int maxProfit(vector<int>& prices,int idx,int trans,int k,int n, vector<vector<int>>& dp) {
        if(idx==n || trans==k)
          return 0;

          if(dp[idx][trans]!=-1)
           return dp[idx][trans];

        if(trans%2==0) //buy
        {
            int a= (-prices[idx]+maxProfit(prices,idx+1,trans+1,k,n,dp)); 
            int b=maxProfit(prices,idx+1,trans,k,n,dp); 
            return dp[idx][trans]=max(a,b);
        } 
        else  //sell
        {
            int a= prices[idx]+maxProfit(prices,idx+1,trans+1,k,n,dp); 
            int b=maxProfit(prices,idx+1,trans,k,n,dp); 
             return dp[idx][trans]= max(a,b);
        }
        
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2*k+1,-1));
        // return maxProfit(prices,0,0,2*k,prices.size(),dp);

        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
       int x=2*k;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=x-1;j>=0;j--) //can reverse this if the values are not dependent on curr row being filled
            {
               if(j%2==0)
               {
                dp[i][j]=max(-prices[i]+dp[i+1][j+1],dp[i+1][j]);
               }
               else
                 dp[i][j]=max(prices[i]+dp[i+1][j+1],dp[i+1][j]);
            }
        }

        return dp[0][0]; // check how are we passing for top down
    }
};
*************************************************************************************************************************************************

 vector<int> front(2*k+1,0), curr(2*k+1,0);
       int x=2*k;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=x-1;j>=0;j--) //can reverse this if the values are not dependent on curr row being filled
            {
               if(j%2==0)
               {
                curr[j]=max(-prices[i]+front[j+1],front[j]);
               }
               else
                 curr[j]=max(prices[i]+front[j+1],front[j]);
            }
            front=curr;
        }

        return curr[0]; // check how are we passing for top down

******************************************************************************************************************
  int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2*k+1,-1));
        // return maxProfit(prices,0,0,2*k,prices.size(),dp);

        // vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
        vector<int> front(2*k+1,0);
       int x=2*k;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=x-1;j>=0;j--) //can reverse this if the values are not dependent on curr row being filled
            {
               if(j%2==0)
               {
                front[j]=max(-prices[i]+front[j+1],front[j]);
               }
               else
                 front[j]=max(prices[i]+front[j+1],front[j]);
            }
        }

        return front[0]; // check how are we passing for top down
    }
************************************************************************************************************************************************************************
class Solution {
public:

    int maxProfit(int p, vector<int>& prices) {
         int n=prices.size();
        vector<vector<int>> after(2,vector<int>(p+1,0));
         vector<vector<int>> curr(2,vector<int>(p+1,0));


         for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= 1; j++) {
            for (int k = 1; k <= p; k++) {  // skip k == 0
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
         

         return after[1][p];
    }
};

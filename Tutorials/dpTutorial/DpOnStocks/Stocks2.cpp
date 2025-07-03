class Solution {
public:
     int maxProfit(vector<int>& prices,int idx,bool buy,int n,int profit) {
        if(idx==n)
          return profit;

        if(buy)
        {
            int a=maxProfit(prices,idx+1,false,n,profit-prices[idx]); 
            int b=maxProfit(prices,idx+1,true,n,profit); 
            return max(a,b);
        } 
        else
        {
            int a=maxProfit(prices,idx+1,true,n,profit+prices[idx]); 
            int b=maxProfit(prices,idx+1,false,n,profit); 
             return max(a,b);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        return maxProfit(prices,0,true,prices.size(),0);
    }
};
******************************************************************************************************************************************************



class Solution {
public:
     int maxProfit(vector<int>& prices,int idx,bool buy,int n, vector<vector<int>>& dp) {
        if(idx==n)
          return 0;

          if(dp[idx][buy]!=-1)
           return dp[idx][buy];

        if(buy)
        {
            int a= (-prices[idx]+maxProfit(prices,idx+1,false,n,dp)); 
            int b=maxProfit(prices,idx+1,true,n,dp); 
            return dp[idx][buy]=max(a,b);
        } 
        else
        {
            int a= prices[idx]+maxProfit(prices,idx+1,true,n,dp); 
            int b=maxProfit(prices,idx+1,false,n,dp); 
             return dp[idx][buy]= max(a,b);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // return maxProfit(prices,0,true,prices.size(),dp);

         vector<vector<int>> dp(n+1,vector<int>(2,0));

         for(int j=0;j<2;j++)
           dp[n][j]=0;

         // for(int i=n-1;i>=0;i--)  
         // {
         //    for(int j=1;j>=0;j--)
         //    {
         //        if(j)
         //         dp[i][j]= max((-prices[i]+dp[i+1][0]),dp[i+1][1]);
         //        else
         //          dp[i][j]=max(prices[i]+dp[i+1][1],dp[i+1][0]) ;
         //    }
         // }
         for(int i=n-1;i>=0;i--)  
         {
            dp[i][1]= max((-prices[i]+dp[i+1][0]),dp[i+1][1]);
            dp[i][0]=max(prices[i]+dp[i+1][1],dp[i+1][0]) ;
         }

         return dp[0][1];
    }
};

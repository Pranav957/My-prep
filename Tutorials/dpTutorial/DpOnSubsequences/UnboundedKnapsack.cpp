// User function Template for C++

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity,int n, vector<vector<int>> dp) {
        // code here
        if(n==0 || capacity==0)
          return 0;
          
          if(dp[n][capacity]!=-1)
             return dp[n][capacity];  
          
          if(wt[n-1]<=capacity)
          {
              int a=val[n-1]+knapSack(val,wt,capacity-wt[n-1],n,dp);
              int b=knapSack(val,wt,capacity,n-1,dp);
              return dp[n][capacity]= max(a,b);
          }
          return dp[n][capacity]= knapSack(val,wt,capacity,n-1,dp);
        
    }
 int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        // vector<vector<int>> dp(n+1,vector<int>(capacity+1,-1));
        // return knapSack(val,wt,capacity,val.size(),dp);
        
           vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));
           
           for(int j=0;j<capacity+1;j++)
                dp[0][j]=0;
           
           for(int i=0;i<n+1;i++)
             dp[i][0]=0;
           
           for(int i=1;i<n+1;i++)
           {
               for(int j=1;j<capacity+1;j++)
               {
                   if(wt[i-1]<=j)
                   {
                       int a=val[i-1]+dp[i][j-wt[i-1]];
                       int b=dp[i-1][j];
                       dp[i][j]=max(a,b);
                   }
                   else
                    dp[i][j]=dp[i-1][j];
               }
           }
           
           return dp[n][capacity];
             
             

    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        // vector<vector<int>> dp(n+1,vector<int>(capacity+1,-1));
        // return knapSack(val,wt,capacity,val.size(),dp);
        
        //   vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));
           
        //   for(int j=0;j<capacity+1;j++)
        //         dp[0][j]=0;
           
        //   for(int i=0;i<n+1;i++)
        //      dp[i][0]=0;
        
        vector<int> prev(capacity+1,0);
        vector<int> curr(capacity+1,0);
           
           for(int i=1;i<n+1;i++)
           {
               for(int j=1;j<capacity+1;j++)
               {
                   if(wt[i-1]<=j)
                   {
                       int a=val[i-1]+curr[j-wt[i-1]];
                       int b=prev[j];
                       curr[j]=max(a,b);
                   }
                   else
                    curr[j]=prev[j];
               }
               prev=curr;
           }
           
           return prev[capacity];
             
    }
};

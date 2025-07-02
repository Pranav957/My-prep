class Solution {
public:
  int numDistinct(string s, string t,int m,int n, vector<vector<int>> &dp) {
     if(n==0)
      return 1;
     if(m==0)
      return 0;

      if(dp[m][n]!=-1)
       return dp[m][n];

      if(s[m-1]==t[n-1])
       return dp[m][n]=numDistinct(s,t,m-1,n-1,dp)+numDistinct(s,t,m-1,n,dp);
     
     return dp[m][n]=numDistinct(s,t,m-1,n,dp);
  }
    int numDistinct(string s, string t) {
        const int MOD = 1e9 + 7;
        int m=s.size();
        int n=t.size();
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // return numDistinct(s,t,m,n,dp);
         vector<vector<int>> dp(m+1,vector<int>(n+1,0));

         for(int j=0;j<n+1;j++)
         dp[0][j]=0;

         for(int i=0;i<m+1;i++)
          dp[i][0]=1;

          for(int i=1;i<m+1;i++)
          {
            for(int j=1;j<n+1;j++)
            {
                if(s[i-1]==t[j-1])
                  dp[i][j]=(dp[i-1][j-1])%MOD+(dp[i-1][j])%MOD;
                else
                 dp[i][j]=dp[i-1][j];  
            }
          }

          return dp[m][n];
    }
};
******************************************************************************************************************
int numDistinct(string s, string t) {
        const int MOD = 1e9 + 7;
        int m=s.size();
        int n=t.size();
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // return numDistinct(s,t,m,n,dp);
        //  vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        //  for(int j=0;j<n+1;j++)
        //  dp[0][j]=0;

        //  for(int i=0;i<m+1;i++)
        //   dp[i][0]=1;

        vector<int> prev(n+1,0),curr(n+1,0);

         prev[0]=1;
          for(int i=1;i<m+1;i++)
          {
            curr[0]=1;
            for(int j=1;j<n+1;j++)
            {
                if(s[i-1]==t[j-1])
                  curr[j]=(prev[j-1])%MOD+(prev[j])%MOD;
                else
                 curr[j]=prev[j];  
            }
            prev=curr;
          }

          return curr[n];
    }

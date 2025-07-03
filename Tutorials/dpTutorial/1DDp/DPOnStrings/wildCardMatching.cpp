class Solution {
public:
    bool isMatch(string s, string p,int m,int n, vector<vector<int>>& dp) {
       if(m==0 && n==0)
        return 1;
       if(m>0 && n==0)
         return 0;
       if(m==0 && n>0)
       {
        for(int i=0;i<n;i++)
         {
            if(p[i]!='*')
             return false;
         }
          return true; 
       }   

         if(dp[m][n]!=-1)
           return dp[m][n];

         if(s[m-1]==p[n-1] || p[n-1]=='?') 
            return dp[m][n]=isMatch(s,p,m-1,n-1,dp);
           
         if(p[n-1]=='*')
         {
            int a=isMatch(s,p,m-1,n,dp);
            int b=isMatch(s,p,m,n-1,dp);
            return dp[m][n]=a|| b;
         }
         return dp[m][n]=false;
    }
     bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // return isMatch(s,p,s.size(),p.size(),dp);
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<m+1;i++)
         dp[i][0]=0;

         for(int j=1;j<n+1;j++)
         {
            dp[0][j]=1;
            for(int i=0;i<j;i++)
           {
            if(p[i]!='*')
             dp[0][j]=0;
           } 
         }

          dp[0][0]=1;

          for(int i=1;i<m+1;i++)
          {
            for(int j=1;j<n+1;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                 dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                 dp[i][j]=dp[i-1][j]||dp[i][j-1]; 
                else
                 dp[i][j]=0; 
            }
          }
          return dp[m][n];
     }
};

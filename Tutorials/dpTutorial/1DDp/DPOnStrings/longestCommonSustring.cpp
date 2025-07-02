int solve(string &s1, string &s2, int i, int j) {
        if(i == 0 || j == 0) return 0;


        int ans= solve(s1, s2, i - 1, j - 1);
        
        if(s1[i-1]==s2[j-1])
         ans=ans+1;
         
         return ans;
         
    }
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n=s1.length();
        int m=s2.length();
        return solve(s1,s2,n,m);
    }


int longestCommonSubstr(string text1, string text2) {
        // int m = s1.length(), n = s2.length();
        // vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(max(m, n) + 1, -1)));
        // return solve(s1, s2, m, n, 0, dp);
        int m=text1.length();
        int n=text2.length();

        int** dp=new int*[m+1];
        for(int i=0;i<=m;i++)
        {
            dp[i]=new int[n+1];
        }

        for(int i=0;i<m+1;i++)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<n+1;j++)
          dp[0][j]=0;
          
          int ans=0;

          for(int i=1;i<m+1;i++)
          {
            for(int j=1;j<n+1;j++)
               if(text1[i-1]==text2[j-1])
              {
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
              }     
              else
              {
                dp[i][j]=0;
              }  
          }

          return ans;
    }

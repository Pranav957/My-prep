class Solution {
public:
    bool checkValidString(string s,int ind, int cnt,int n,vector<vector<int>>& dp) {
        if(cnt<0)
         return false;

         if(ind==n)
          return cnt==0;

          if(dp[ind][cnt]!=-1)
            return dp[ind][cnt];

          if(s[ind]=='(')
            return dp[ind][cnt]=checkValidString(s,ind+1,cnt+1,n,dp);
          if(s[ind]==')')
            return dp[ind][cnt]=checkValidString(s,ind+1,cnt-1,n,dp);

           return dp[ind][cnt]=checkValidString(s,ind+1,cnt+1,n,dp) || checkValidString(s,ind+1,cnt-1,n,dp)
           || checkValidString(s,ind+1,cnt,n,dp);    
    }
    bool checkValidString(string s) {

        int n=s.length();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return checkValidString(s,0,0,s.length(),dp);
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        dp[n][0] = 1;

        for(int i=n-1;i>=0;i--)
        {
            // for(int j=n-1;j>=0;j--) // as values are from next row only can traverse in any direction
            for(int j=0;j<n;j++)
            {
                if(s[i]=='(')
                {
                    // if(j+1<=n)
                     dp[i][j]=dp[i+1][j+1];
                }
                else if(s[i]==')')
                {
                    if(j>=1)
                    dp[i][j]=dp[i+1][j-1];
                    
                 }
                 else {
                    bool chooseOpen =  dp[i+1][j+1];
                    bool chooseClose = (j >= 1) && dp[i+1][j-1];
                    bool chooseEmpty = dp[i+1][j];
                    dp[i][j] = chooseOpen || chooseClose || chooseEmpty;
                 }   

            }
        }
         return dp[0][0];
    }
};

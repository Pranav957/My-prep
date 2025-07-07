class Solution {
public:
  bool isPalindrome(string & s,int i,int j)
  {
    while(i<j)
    {
        if(s[i]!=s[j])
         return false;
         i++;
         j--;
    } 
    return true;
  }
  int minCut(string s,int i,int j,vector<vector<int>>& dp) {
        if(i>j)
          return 0;
        if(isPalindrome(s,i,j))
         return 0;

         if(dp[i][j]!=-1)
           return dp[i][j];

         int mini=INT_MAX; 

       for(int k=i;k<j;k++)
       {
         int cost=1+minCut(s,i,k,dp)+minCut(s,k+1,j,dp);
         mini=min(cost,mini);
       } 
       return dp[i][j]= mini;  
    }
    int minCut(string s) {
        int n=s.length();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return minCut(s,0,s.length()-1,dp);
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=n-1;j++)
            {
                if(i>j || isPalindrome(s,i,j)) continue;
                int mini=INT_MAX;
                for(int k=i;k<j;k++)
                {
                    int cost=1+dp[i][k]+dp[k+1][j];
                    mini=min(cost,mini);
                } 
               dp[i][j]= mini;  
            }
        }
        return dp[0][n-1];
    }
};

***************************************************************************************************************************************************************************************888
  class Solution {
public:
  bool isPalindrome(string & s,int i,int j)
  {
    while(i<j)
    {
        if(s[i]!=s[j])
         return false;
         i++;
         j--;
    } 
    return true;
  }
  int minCut(string s,int i,int n,vector<int>& dp) { //min cuts required for string starting from i
        if(i==n) return 0;

        if(dp[i]!=-1)
         return dp[i];

        int mini=INT_MAX;

        for(int j=i;j<n;j++)
        {
            if(isPalindrome(s,i,j))
            {
                int cost=1+minCut(s,j+1,n,dp);
                mini=min(cost,mini);
            }
        }
        return dp[i]=mini; 
    }
    int minCut(string s) {
        int n=s.length();
        // vector<int> dp(n+1,-1);
        // return minCut(s,0,n,dp)-1;
         vector<int> dp(n+1,0);

         for(int i=n-1;i>=0;i--)
         {
            int mini=INT_MAX;
            for(int j=i;j<n;j++)
            {
                if(isPalindrome(s,i,j))
                {
                    int cost=1+dp[j+1];
                    mini=min(cost,mini);
                }
            }
            dp[i]=mini; 
         }
         return dp[0]-1;
    }
};

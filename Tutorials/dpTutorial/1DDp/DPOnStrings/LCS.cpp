class Solution {
public:
int longestCommonSubsequence(string text1, string text2,int m, int n,int** dp) {
        if(m==0 || n==0)
          return 0;
        if(dp[m][n]!=-1)
         return dp[m][n];
          if(text1[m-1]==text2[n-1])
            return dp[m][n]= 1+ longestCommonSubsequence(text1,text2,m-1,n-1,dp);

           int a=longestCommonSubsequence(text1,text2,m-1,n,dp);
           int b=longestCommonSubsequence(text1,text2,m,n-1,dp) ;
           return dp[m][n]= max(a,b);
    }
    // int longestCommonSubsequence(string text1, string text2){
    //     int m=text1.length();
    //     int n=text2.length();

    //     int** dp=new int*[m+1];
    //     for(int i=0;i<=m;i++)
    //     {
    //         dp[i]=new int[n+1];
    //         for(int j=0;j<=n;j++)
    //           dp[i][j]=-1;
    //     }
    //     return longestCommonSubsequence(text1,text2,text1.length(),text2.length(),dp);
    // }
    int longestCommonSubsequence(string text1, string text2) {
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

          for(int i=1;i<m+1;i++)
          {
            for(int j=1;j<n+1;j++)
               if(text1[i-1]==text2[j-1])
                 dp[i][j]=1+dp[i-1][j-1];
               else
               {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
               }  
          }

          return dp[m][n];
    }
};

************************************************************************************************************************************
int longestCommonSubsequence(string text1, string text2) {
         int m=text1.length();
        int n=text2.length();

        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);

          for(int i=1;i<m+1;i++)
          {
            for(int j=1;j<n+1;j++)
               if(text1[i-1]==text2[j-1])
                 curr[j]=1+prev[j-1];
               else
               {
                curr[j]=max(curr[j-1],prev[j]);
               }
               prev=curr;  
          }

          return prev[n];
    }

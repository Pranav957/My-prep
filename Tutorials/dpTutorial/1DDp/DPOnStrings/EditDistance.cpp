class Solution {
public:
int minDistance(string word1, string word2,int m,int n,int** dp){
   if(m==0)
      return n;
    if(n==0)
       return m;

   if(dp[m][n]!=-1)
      return dp[m][n];

     if(word1[m-1]==word2[n-1])
       return dp[m][n]=minDistance(word1,word2,m-1,n-1,dp);

     int insertOp = minDistance(word1, word2, m, n - 1,dp);
    int deleteOp = minDistance(word1, word2, m - 1, n,dp);
    int replaceOp = minDistance(word1, word2, m - 1, n - 1,dp);

    return dp[m][n]= 1 + min({insertOp, deleteOp, replaceOp});  
}
    // int minDistance(string word1, string word2) {
    //     int m=word1.length();
    //     int n=word2.length();
    //     int** dp=new int*[m+1];
    //     for(int i=0;i<=m;i++)
    //     {
    //         dp[i]=new int[n+1];
    //         for(int j=0;j<=n;j++)
    //           dp[i][j]=-1;
    //     }
    //     return minDistance(word1,word2,word1.length(),word2.length(),dp);
    // }
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        

        int** dp=new int*[m+1];
        for(int i=0;i<m+1;i++)
        {
            dp[i]=new int[n+1];
        }

        for(int i=0;i<m+1;i++)
        {
            dp[i][0]=i;
        }
        for(int j=0;j<n+1;j++)
          dp[0][j]=j;

        dp[0][0]=0;
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(word1[i-1]==word2[j-1])
                  dp[i][j]=dp[i-1][j-1];

                 else
                 {
                    int insertop=dp[i][j-1];
                    int deleteOp=dp[i-1][j];
                    int replaceOp=dp[i-1][j-1];
                    dp[i][j]=1+min({insertop,deleteOp,replaceOp});
                 } 
            }
        }
        return dp[m][n];  
    }
};

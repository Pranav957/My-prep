int editDistance(string s1, string s2,int ** dp) {
	// Write your code here
  int m=s1.length();
  int n=s2.length();

  if(s1.length()==0)
    return s2.length();
  if(s2.length()==0)
    return s1.length();

    if(dp[m][n]!=-1)
      return dp[m][n];

int ans;
    if(s1[0]==s2[0])
     ans= editDistance(s1.substr(1),s2.substr(1),dp);
   else
   {
      int a=editDistance(s1.substr(1),s2,dp);
      int b=editDistance(s1,s2.substr(1),dp);
      int c=editDistance(s1.substr(1),s2.substr(1),dp);
       ans= 1+min(a,min(b,c));
   }
   dp[m][n]=ans;
   return ans;

}
int editDistance(string s1, string s2) {
    
    int m=s1.length();
    int n=s2.length();

    int** dp=new int*[m+1];
    for(int i=0;i<=m;i++)
    {
      dp[i]=new int[n+1];
      // for(int j=0;j<=n;j++)
      //   dp[i][j]=-1;
    }
  //  return  editDistance(s1,s2,dp);
  for(int i=0;i<=m;i++)
  {
    dp[i][0]=i;
  }
  for(int j=0;j<=n;j++)
    dp[0][j]=j;
    dp[0][0]=0;
    for(int i=1;i<m+1;i++)
    {
      for(int j=1;j<n+1;j++)
        if(s1[m-i]==s2[n-j])
          dp[i][j]=dp[i-1][j-1];
        else 
          dp[i][j]=1+min(dp[i-1][j], min(dp[i][j-1],dp[i-1][j-1]));  
    }
    return dp[m][n];
}
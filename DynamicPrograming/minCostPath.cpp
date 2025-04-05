int helper(int ** input, int i, int j, int m, int n,int ** dp)
{
     if(i==m-1 && j==n-1)
       return input[i][j];
     if( i>=m  || j>=n)
      return INT_MAX;
       if(dp[i][j]!=-1)
        return dp[i][j];
      int a=  helper(input,i+1,j,m,n,dp);  
      int b= helper(input,i,j+1,m,n,dp);
      int c=helper(input,i+1,j+1,m,n,dp);
      return dp[i][j]= input[i][j]+min(a,min(b,c));

}
int minCostPath(int **input, int m, int n)
{
   //Write your code here
  int ** dp=new int*[m+1];
  for(int i=0;i<=m;i++)
  {
      dp[i]=new int[n+1];
      for(int j=0;j<=n;j++)
        dp[i][j]=-1;
  }

  return helper(input,0,0,m,n,dp);
}
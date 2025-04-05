int maxMoneyLootedH(int *arr, int n,int *dp)
{
	//Write your code here
  if(n<=0)
    return 0;
  
  if(dp[n]!=-1)
    return dp[n];
    int a=arr[n-1]+ maxMoneyLootedH(arr,n-2,dp);
    int b=maxMoneyLootedH(arr,n-1,dp);
    return dp[n]= max(a,b);

}
int maxMoneyLooted(int *arr, int n){
   int * dp=new int[n+1];
  //  for(int i=0;i<n+1;i++)
  //   dp[i]=-1;
  //   return maxMoneyLootedH(arr,n,dp);
  dp[0]=0;
  dp[1]=arr[0];
  for(int i=2;i<n+1;i++ )
  { 
     dp[i]=max(arr[i-1]+dp[i-2],dp[i-1]);
  }
  return dp[n];
}
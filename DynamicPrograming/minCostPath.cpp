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


int minCostPath(int arr[][3],int m,int n,int i,int j)
{
    // if(i==m-1 && j==n-1)
    // {
    //     return arr[i][j];
    // }
    
    // if(i>=m || j>=n)
    // {
    //     return INT_MAX;
    // }
    
    // int a=minCostPath(arr,m,n,i+1,j+1);
    // int b=minCostPath(arr,m,n,i+1,j);
    // int c=minCostPath(arr,m,n,i,j+1);
    
    // return arr[i][j]+min({a,b,c});
    
    int** output=new int*[m];
    for(int i=0;i<m;i++)
    {
        output[i]=new int[n];
    }
    
    output[m-1][n-1]=arr[m-1][n-1];
    
    for(int i=m-1;i>=0;i--)
    {
        int a=INT_MAX,b=INT_MAX,c=INT_MAX;
        for(int j=n-1;j>=0;j--)
        {
            if(i==m-1 && j==n-1)
              continue;
              
              if(i+1<m && j+1<n)
                a=output[i+1][j+1];
              if(i+1<m)  
              b=output[i+1][j];
              if(j+1<n)
                c=output[i][j+1];
                
            output[i][j]= arr[i][j]+min({a,b,c});        
        }
    }
    return output[0][0];
   
    
}

int main()
{
    // int m,n;
    // cin >> m >> n;
    int m=3,n=3;
    
    int arr[][3]={{1,2,3},{4,5,6},{6,7,8}};
    // int** arr=new int*[m];
    // for(int i=0;i<m;i++)
    // {
    //     arr[i]=new int[n];
    //     for(int j=0;j<n;j++)
    //       cin >> arr[i][j];
    // }
    int a= minCostPath(arr,n,m,0,0);
    cout<<a<<" ";

    return 0;
}

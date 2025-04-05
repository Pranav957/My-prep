const unsigned int M=1e9+7;
int balancedBTs_helper(int n,long* arr) {
    // Write your code here
    if(n==1)
      return 1;
    if(n==2)
       return 3;
     if(arr[n]!=-1)
       return arr[n];  
    
    int x=balancedBTs_helper(n-1,arr);
    int y=balancedBTs_helper(n-2,arr);

    int temp1=(int)(((long)(x)*x)%M);
    int temp2=(int)((2*(long)(x)*y)%M);
    int ans=(temp1+temp2)%M;

    
    arr[n]=ans;
    return ans;     
}
int balancedBTs(int n)
{
  long *arr=new long[n+1];
  for(int i=0;i<n+1;i++)
     arr[i]=-1;
   return balancedBTs_helper(n,arr);  
}

const unsigned int M = 1e9 + 7;
int balancedBTs_helper(int n, long *arr) {
  // Write your code here
  if (n == 1)
    return 1;
  if (n == 2)
    return 3;
  if (arr[n] != -1)
    return arr[n];

  int x = balancedBTs_helper(n - 1, arr);
  int y = balancedBTs_helper(n - 2, arr);

  int temp1 = (int)(((long)(x)*x) % M);
  int temp2 = (int)((2 * (long)(x)*y) % M);
  int ans = (temp1 + temp2) % M;

  arr[n] = ans;
  return ans;
}
int BbalancedBTs(int n) {
  long *arr = new long[n + 1];
  for (int i = 0; i < n + 1; i++)
    arr[i] = -1;
  return balancedBTs_helper(n, arr);
}
int balancedBTs(int n)
{
  long *arr=new long[n+1];
  arr[0]=1;
  arr[1]=1;
  for(int i=2;i<=n;i++)
  {
     int x=arr[i-1];
     int y=arr[i-2];
     int temp1 = (int)(((long)(x)*x) % M);
     int temp2 = (int)((2 * (long)(x)*y) % M);
     int ans = (temp1 + temp2) % M;

     arr[i] = ans;
  }
  return arr[n];
}
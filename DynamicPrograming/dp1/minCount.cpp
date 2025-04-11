#include<bits/stdc++.h>
int squareSum(int n)
{
    if(n<=1)
      return n;
      
      int min=INT_MAX;
      for(int i=1;i<sqrt(n);i++)
      {
          int x=i*i;
          int ans=1+squareSum(n-x);
          if(ans<min)
            min=ans;
          
      }
      return min;
    
}

int squareSum(int n)
{
   
    
    int* arr=new int[n+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=n;i++)
    {
        int min=INT_MAX;
        for(int j=1;j<sqrt(i);j++)
        {
            int x=j*j;
            int ans=1+arr[i-x];
            if(ans<min)
              min=ans;
        }
        arr[i]=min;
    }
    return arr[n];
    
}

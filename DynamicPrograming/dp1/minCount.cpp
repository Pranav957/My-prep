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

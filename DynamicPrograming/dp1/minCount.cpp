#include<bits/stdc++.h>
int minCount(int n)
{
	//Write your code here
	if(n<=3)
	  return n;

int min=INT_MAX;
	  for(int i=1;i<=sqrt(n);i++)
	  {
		  int v=i*i;
		   int x=1+minCount(n-v);
         if(x<min)
		   min=x;
	  }
	  return min;
}
#include <cmath>
/*int getAllWays(int a, int b,int l,int* arr) {
	// Write your code here
	if(a==0)
	   return 1;
	if(l>a)
	   return 0; 
	   if(arr[a]!=-1)
	     return arr[a];  
	int ans=0;
	ans+=getAllWays( a-pow(l,b),  b,l+1,arr);
	ans+=getAllWays(a,  b, l+1,arr);
	arr[a]=ans;
	return ans;
}
int getAllWays(int a, int b)
{
	int* arr=new int[a+1];
	for(int i=0;i<a+1;i++)
	       arr[i]=-1;
   getAllWays(a,b,1,arr);	 
}*/
int getAllWays(int a, int b,int l=1) {
	// Write your code here
	if(a==0)
	   return 1;
	   if(a<0)
	     return 0;
	if(l>a)
	   return 0;   
	int ans=0;
	ans+=getAllWays( a-pow(l,b),  b,l+1);
	ans+=getAllWays(a,  b, l+1);
	return ans;
}


/*#include<cmath>
int getAllWays(int a, int b,) {
	// Write your code here
	if(a==0)
	   return 1;
	   if(i==0)
	     return 0;
	if(a<0)
	   return 0;
	   int x=0;
	   for(int i=sqrt(a);i>=1;i--)
	   {
             x+=getAllWays(a-pow(i,b),i-1);
	   }
	   return x;
}*/

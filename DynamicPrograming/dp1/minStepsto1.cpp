#include<climits>
int countMinStepsToOne(int n)
{
	//Write your code here
	if(n==1)
	  return 0;

int a=INT_MAX,b=INT_MAX,c=INT_MAX;
	 a= countMinStepsToOne(n-1);
	 if(n%2==0)
	  b=countMinStepsToOne(n/2);
	 if(n%3==0)
	  c=countMinStepsToOne(n/3);

	  return 1+min(a,min(b,c)); 

}

#include<climits>
int countStepsToOne(int n)
{
	//Write your code here
	int* arr=new int[n+1];
	arr[1]=0;
	for(int i=2;i<=n;i++)
	{
		int x,a=INT_MAX, b=INT_MAX, c=INT_MAX;
		if(i%2==0)
		{
			x=i/2;
			a=arr[x]+1;
		}
		 if(i%3==0)
		{
			x=i/3;
			b=arr[x]+1;
		}
		
			x=i-1;
			c=arr[x]+1;
	  arr[i]=min(a, min(b,c));	 
	} 
	return arr[n];
}
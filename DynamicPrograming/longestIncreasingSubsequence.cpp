/*#include<climits>
int longestIncreasingSubsequence(int* arr, int n,int x,int* out) {
	// Write your code here
	if(n==0)
	  return 0;
	  int a=0;
	  if(out[n]!=-1)
	    return out[n];
   if(arr[0]>x)
      a=1+longestIncreasingSubsequence(arr+1,n-1,arr[0],out);
	int b=longestIncreasingSubsequence(arr+1,n-1,x,out );
	out[n]= max(a,b);  
	return out[n];
}
int longestIncreasingSubsequenceS(int *arr, int n) 
{ 
	int *out = new int[n + 1];
	for(int i=0;i<=n;i++)
	{
		out[i]=-1;
	}
	int int_mn=INT_MIN;
	return longestIncreasingSubsequence(arr,n,int_mn,out);
}*/

int longestIncreasingSubsequence(int* input, int n) {
	// Write your code here
	int* output=new int[n];
	output[0]=1;
	for(int i=1;i<n;i++)
	{
		output[i]=1;
		for(int j=i-1;j>=0;j--)
		{
			if(input[j]>=input[i])
			  continue;
			int possible_ans=output[j]+1;
			if(possible_ans>output[i])
			  output[i]=possible_ans;
		}
	}
	int best=0;
	for(int i=0;i<n;i++)
	{
		if(best<output[i])
		  best=output[i];
	}
	delete output;
	return best;
}
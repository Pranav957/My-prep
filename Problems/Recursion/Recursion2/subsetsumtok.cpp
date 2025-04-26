/***
if(n==0)
    {
      output[0][0]=0;
        return 1;
    }
    int a=subsetSumToK(input+1,n-1,output,k);
    for(int i=0;i<a;i++)
    {
        output[i+a][0]=ouput[i][0]+1;
        for(int j=1;j<output[i][0];j++)
        {
            output[a+i][j+1]=output[i][j];
        }
        output[i+a][1]=input[0];
    }  
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don?t print the subsets, just save them in output.
***/
#include <iostream>
using namespace std;
int subsetSumToK(int input[],int si, int n, int output[][50], int k,int op[],int prevopsize)
{
    if(si==n)
    {
        if(k==0)
        {
            static int x=0;
            output[x][0]=prevopsize;
          for(int i=0;i<prevopsize;i++)
          {
            output[x][i+1]=op[i];
          } 
            x++;
            return 1;
        }
        
         return 0;
    }
    int newopsize=prevopsize+1;
    int newoparr[newopsize]={0};
    int i=0;
    for(;i<newopsize-1;i++)
        newoparr[i]=op[i];
     if(input[si]<=k && k!=0)
       newoparr[i]=input[si];
    int a=subsetSumToK(input,si+1,n,output,k,op,prevopsize);
    int b= subsetSumToK(input,si+1,n,output,k-input[si],newoparr,newopsize);
     return a+b;
}
int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    int *op=new int[0];
    return subsetSumToK(input,0,n,output,k,op,0);

}
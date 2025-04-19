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

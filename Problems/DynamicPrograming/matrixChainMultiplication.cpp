#include<climits>
int matrixChainMultiplication(int* arr,int s,int e,int** out)
{
    if(s==e)
      return 0;
    if(s==e-1)
        return 0;  
        if(out[s][e]!=-1)
            return out[s][e];
    int Min=INT_MAX;
    for(int i=s+1;i<e;i++)
    {
        int x=(arr[s]*arr[i]*arr[e])+matrixChainMultiplication(arr, s,i,out)+matrixChainMultiplication(arr, i,e,out);
        if(x<Min)
          Min =x;
    } 
    out[s][e]=Min;
    return Min;
}
int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    
    int** output=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        output[i]=new int[n+1];
        for(int j=0;j<=n;j++)
          output[i][j]=-1;
    }
    return matrixChainMultiplication(arr, 0, n,output);
}
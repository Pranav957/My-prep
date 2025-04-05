void subsetSumToK(int input[],int si, int n,int k,int op[],int prevopsize)
{
    if(si==n)
    {
        if(k==0)
        {
            for(int i=0;i<prevopsize;i++)
          {
            cout<<op[i]<<" ";
          }
            cout<<endl;
        }
        return;
    }
    int newopsize=prevopsize+1;
    int newoparr[newopsize]={0};
    int i=0;
    for(;i<newopsize-1;i++)
        newoparr[i]=op[i];
     if(input[si]<=k && k!=0)
       newoparr[i]=input[si];
    subsetSumToK(input,si+1,n,k,op,prevopsize);
    subsetSumToK(input,si+1,n,k-input[si],newoparr,newopsize);
     
}
void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int *op=new int[0];
    return subsetSumToK(input,0,size,k,op,0);
}

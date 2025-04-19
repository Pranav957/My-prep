void printSubsetsOfArray(int input[], int si,int output[],int size,int prevopsize)
{
    if(si==size)
    {
        for(int i=0;i<prevopsize;i++)
        {
            cout<<output[i]<<" ";
        } 
        cout<<endl;
         return;
    } 
    int newopsize=prevopsize+1;
    int newoparr[newopsize]={0};
    int i=0;
    for(;i<newopsize-1;i++)
        newoparr[i]=output[i];
    newoparr[i]=input[si];
    printSubsetsOfArray(input,si+1,output,size,prevopsize);
    printSubsetsOfArray(input,si+1,newoparr,size,newopsize);
   
}
void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    
   // int * a=new int[size];
    int *output=new int[0];
    printSubsetsOfArray(input,0,output,size,0);
    
}
/*void printSubsetsOfArray(int input[], int size,int a[],int i)
{
    if(size==0)
    {
      for(int j=0;j<=i;j++)
      {
          cout<<a[i]<<" ";
      }
        cout<<endl;
        return;
    }
    printSubsetsOfArray(input+1,size-1,a,i);
    a[++i]=input[0];
    printSubsetsOfArray(input+1,size-1,a,i);
    
    
}
void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    
   // int * a=new int[size];
    int a[size]={0};
    printSubsetsOfArray(input,size,a,-1);
    
}*/



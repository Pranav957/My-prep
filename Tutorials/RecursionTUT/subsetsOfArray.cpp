int subset(int input[], int n, int output[][20]) {
    // Write your code here
   if(n==0)
   {
       output[0][0]=0;
       return 1;
   } 
    int a=subset(input+1,n-1,output);
        
      for(int i=0;i<a;i++)
      {
         
          output[a+i][0]=output[i][0]+1;
          for( int j=1 ;j<=output[i][0];j++)
          {
              output[a+i][j+1]=output[i][j];
          } 
          output[a+i][1]=input[0];
      }
       
    return 2*a;
}

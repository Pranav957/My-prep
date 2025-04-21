/*
You can use minimum value of integer as -2147483647 and 
maximum value of integer as 2147483647
*/
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<LargestRowColumn<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
#define INT_MIN -2147483648
void findLargest(int **input, int nRows, int mCols)
{
    int  sum =0 , max=INT_MIN, rc=0;
    bool flag=1;
    //Write your code here
    for(int i=0;i<nRows;i++)
    {
         sum=0;
         for(int j=0;j<mCols;j++)
         {
           sum+=input[i][j];
         }

         if(sum>max)
         {
           max=sum;
           rc=i;
           flag=1;
         }
    }
    for(int j=0;j<mCols;j++)
    {
      sum=0;
      for(int i=0;i<nRows;i++)
      {
            sum+=input[i][j];
      }
       if(sum>max)
            {
              max=sum;
              rc=j;
              flag=0;
            }
    }
    
   if(flag)
    {
        cout<<"row  "<<rc<<" "<<max;
    }  
    else
    {
        cout<<"column  "<<rc<<" "<<max;
    }
}

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<WavePrint<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,,,,,
    void wavePrint(int **input, int nRows, int mCols)
{
    //Write your code here
    for(int i=0;i<mCols;i++)
    {
        if(i%2!=0)
        {
            for(int j=nRows-1;j>=0;j--)
            {
                cout<<input[j][i]<<" ";
            }
        }
        else {
            for(int j=0;j<nRows;j++)
        {
            cout<<input[j][i]<<" ";
        }
        }
    }
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<SPIRAL PRINT<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    void spiralPrint(int **input, int nRows, int nCols)
{
    //Write your code here
   int r1=0,c1=0,r2=nRows-1, c2=nCols-1;
   while(r1 <= r2 && c1<= c2){
       for(int i=c1;i<=c2;i++){
           cout<<input[r1][i];
       }
       r1++;

       for(int i=r1; i<= r2; i++){
           cout<<input[i][c2];
       }
       c2--;

       for(int i=c2;i>=c1;i--){
           cout<<input[r2][i];
       }
       r2--;

       for(int i=r2;i>=r1;i--){
           cout<<input[i][c1];
       }
       c1++;

   }
}

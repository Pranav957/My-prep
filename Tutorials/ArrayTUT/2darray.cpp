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

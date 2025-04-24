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
   int rs=0, re=nRows-1;
   int cs=0, ce=nCols-1;
   int element=nRows*nCols;
   while(cs<=ce && rs<=re)
   {
       for(int i=cs;i<=ce;i++)
       {
           cout<<input[rs][i]<<" ";
           element--;
       }
       rs++;
       for(int i=rs; i<=re;i++)
       {
           cout<<input[i][ce]<<" ";
           element--;
       }
       ce--;
       if(rs<=re)
       {
          for(int i=ce;i>=cs;i--)
       {
           cout<<input[re][i]<<" ";
           element--;
       }
       }
       re--;
       if(cs<=ce)
       {
      for(int i=re;i>=rs;i--)
       {
           cout<<input[i][cs]<<" ";
           element--;
       }
       }
       
       cs++;
   }
}

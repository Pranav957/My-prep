// void pushZeroesEnd(int *input, int size)// initialize variable to keep index wehere first non zero element should be placed
// {
//     //Write your code here
//     int placeNonZero=0;
//     for(int i=0;i<size;i++)
//     {
//         if(input[i]!=0)
//         {
//             int temp=input[i];
//             input[i]=input[placeNonZero];
//             input[placeNonZero]=temp;

//             placeNonZero++;
//         }
//     }
// }

void swap(int input [],int i,int j)
{
    int temp=input[i];
    input[i]=input[j];
    input[j]=temp;
}
void pushZeroesEnd(int *input, int size) //find first zero element  and swap with 
{                                                             //first non zero element coming after it
    //Write your code here
    for(int i=0;i<size;i++)
    {
        if(input[i]==0)
        {
            for(int j=i+1;j<size;j++)
             if(input[j]!=0)
             {
                 swap(input,i,j);
                 break;
             }
        }
    }
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Alternate Way<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  void pushZeroesEnd(int *input, int size)
{
    //Write your code here
    int i=0,k=0;
    while(i<size)
    {
        if(input[i]!=0 && k<i)
        {
            int temp=input[k];
            input[k]=input[i];
            input[i]=temp;
            i++;
            k++;
        } 
        else if(input[i]!=0 && k==i)
        {
            i++;
            k++;
        }
        else if(input[i]==0)
            i++;
            
    }
    
}

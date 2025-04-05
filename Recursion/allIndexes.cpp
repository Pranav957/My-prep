/*Problem statement
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in the output array (in increasing order).

Do this recursively. Indexing in the array starts from 0.

Hint:
Try making a helper function with the required arguments and call the helper function from the allIndexes function.*/

#include<iostream>
int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.*/
  static int i=0;
    static int j=0;
    int ans;
    if(size==0)
        return j;
    if(input[i]==x)
    {
        output[j]=i;
        i++;
        j++;
         ans=allIndexes(input,size-1,x,output);
         
    }  
    else
    {
      i++;
         ans=allIndexes(input,size-1,x,output);
        
    }
    
    return ans;

}


/*int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  
  if(size==0)
  {
    return 0;
  }
  int ans=allIndexes(input+1,size-1,x,output);
   for(int i=0;i<ans;i++)
   {
     output[i]++;
   }
   if(input[0]==x)
   {
     for(int i=ans-1;i>=0;i--)
     {
       output[i+1]=output[i];
     }
     output[0]=0;
     return ans+1;
   }
   return ans;

}
/*int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  static int s=size;
    static int count=0;
    int ans;
    if(size==0)
        return count;
    if(input[0]==x)
    {
        output[0]=0;
        count++;
         ans=allIndexes(input+1,size-1,x,output+1);
         
    }  
    else
    {
         ans=allIndexes(input+1,size-1,x,output);
        
    }if(size!=s)
    {   
     for(int i=0;i<ans;i++)
        output[i]++;
    }
    
    
    return ans;

}*/



#include<bits/stdc++.h>

void rotate(int *input, int d, int n)// perform d rotations;
{
    //Write your code here
    for(int i=0;i<d;i++)
    {
        int j,temp=input[0];
        for( j=0;j<n-1;j++)
        {
            input[j]=input[j+1];
        }
        input[j]=temp;
    }
}
void rotate(int *input, int d, int n)//store d elements in array then perform single i+d rotation
{
    //Write your code here
    int arr[d];
    for(int i=0;i<d;i++)
    {
        arr[i]=input[i];
    }
    int i;
    for( i=0;i<n-d;i++)
      input[i]=input[i+d];


      for(int j=0;j<d;j++)
      {
          input[i]=arr[j];
          i++;
      }
   
}
void rotate(int *input, int d, int n)
{
    //Write your code here
    reverse(input,input+n);
    reverse(input+n-d,input+n);
    reverse(input,input+n-d);
}
   
   void rotate(int *input, int d, int n)
{
    reverse(input, input + d);        // Step 1: Reverse first d elements
    reverse(input + d, input + n);    // Step 2: Reverse remaining elements
    reverse(input, input + n);        // Step 3: Reverse entire array
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  void reverse(int i,int j,int* input)
{
     while(j>i)
    {
        int t=input[i];
        input[i]=input[j];
        input[j]=t;
        i++;
        j--;
    }
}
void rotate(int *input, int d, int n)
{
    //Write your code here
     int i=0,j=n-1;
    reverse(i,j,input);
    reverse(i,n-d-1,input);
    reverse(n-d,j,input);
   
}






void rotate(int *input, int d, int n)
{
    //Write your code here
     int arr[d],j;
    for(int i=0;i<d;i++)
    {
        arr[i]=input[i];
    }
    for( j=0;j<n-d;j++)
    {
        input[j]=input[j+d];
    } 
    //j=n-d;
    for(int i=0;i<d;i++)
    {
        input[j]=arr[i];
        j++;
    }
}

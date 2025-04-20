/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>


#include <bits/stdc++.h>
using namespace std;

//After one round smallest element gets first placed at its right position 
void selectionSort(int input[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minElement=input[i], minIndex=i;
       for(int j=i+1;j<n;j++)
       {
          if(input[j]<minElement)
           {
               minElement=input[j];
               minIndex=j;
           }
       }
       int temp=input[i];             // if(i!=minIndex)
       input[i]=input[minIndex];
       input[minIndex]=temp;
    }
}

//After first round largest element gets placed at its right pos
void bubblesort(int input[],int n)
{
    for(int j=0;j<n-1;j++)
    {
        for(int i=0;i<n-1-j;i++)
        {
            if(input[i+1]<input[i])
            {
                int temp=input[i+1];
                input[i+1]=input[i];
                input[i]=temp;
            }
        }
    }
}

void insertionSort(int input,int n)
{
    for(int i=1;i<n;i++)
    {
        int current=int[i];
        int j;
        for(j=i-1;j>=0;j--)
        {
            if(current<arr[j])
              arr[j+1]=arr[j];
            else
             break;
        }
        arr[j+1]=current;
    
    }
}

int main()
{
    
     int input[]={5,5,9,8,3,2,5,7,1};
     
     bubblesort(input,9);
    
    for(int i=0;i<9;i++)
      cout<<input[i]<<" ";
     

    return 0;
}

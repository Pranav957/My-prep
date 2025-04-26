#include<bits/stdc++.h>
using namespace std;
/*void heapSort(int arr[], int n) {
    // Write your code
    for(int i=1;i<n;i++)
    {
       int  childindex=i;
       
        while(childindex>0)
        {
          int parentindex = (i - 1) / 2;
          if (arr[childindex] < arr[parentindex]) {
            int temp = arr[childindex];
            arr[childindex] = arr[parentindex];
            arr[parentindex] = temp;
            }
            else 
             break;
             childindex=parentindex;
        }
    }
    int k = n;
    for(int i=0;i<n;i++)
    {
      int temp = arr[0];
      arr[0] = arr[k - 1];
      arr[k - 1] = temp;
      k = k - 1;
      int parentindex = 0;
      int lchildindex = 2 * parentindex + 1;
      int rchildindex = 2 * parentindex + 2;
      int minindex ;
      while (lchildindex < k) {
           if (rchildindex < k)
          {
              if (arr[rchildindex] < arr[lchildindex]) 
               minindex = rchildindex;
              else
            minindex = lchildindex;
          }
           else
                minindex=lchildindex;
               // cout<<parentindex<<" ";
          if(arr[minindex]<arr[parentindex])
          {
              int temp=arr[minindex];
              arr[minindex]=arr[parentindex];
              arr[parentindex]=temp;
          }
          else 
            break;
            parentindex=minindex;
             lchildindex = 2 * parentindex + 1;
             rchildindex = 2 * parentindex + 2;
        }
    }
}*/
void heapSort(int arr[], int n) {
    // Write your code
    for(int i=1;i<n;i++)
    {
       int  childindex=i;
       
        while(childindex>0)
        {
          
         int parentindex = (childindex - 1) / 2;
          //cout<<childindex<<" "<<parentindex<<endl;
          if (arr[childindex] < arr[parentindex]) {
            int temp = arr[childindex];
            arr[childindex] = arr[parentindex];
            arr[parentindex] = temp;
            }
            else 
                break;
             childindex=parentindex;

        }
    }
    
    int k = n;
    for(int i=0;i<n-1;i++)
    {
      int temp = arr[0];
      arr[0] = arr[k - 1];
      arr[k - 1] = temp;
      k = k - 1;
      int parentindex = 0;
      int lchildindex = 2 * parentindex + 1;
      int rchildindex = 2 * parentindex + 2;
      int minindex ;
      while (lchildindex < k) {
          
           if (rchildindex < k)
          {
              if (arr[rchildindex] < arr[lchildindex]) 
               minindex = rchildindex;
              else
            minindex = lchildindex;
          }
           else
                minindex=lchildindex;
               // cout<<parentindex<<" ";
          if(arr[minindex]<arr[parentindex])
          {
              int temp=arr[minindex];
              arr[minindex]=arr[parentindex];
              arr[parentindex]=temp;
          }
          else 
            break;
            parentindex=minindex;
             lchildindex = 2 * parentindex + 1;
             rchildindex = 2 * parentindex + 2;
        }
    }
}
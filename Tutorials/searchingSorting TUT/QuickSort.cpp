//Select a pivot element and make it go its right position , find count of lements smaller than pivot and put pivot at si+count;
//do the partition to put all the elements smaller than pivot at its left and greater at right, now array will be devided in two parts
#include <bits/stdc++.h>
using namespace std;

void swap(int input[],int x,int y)
{
	int temp=input[x];
	input[x]=input[y];
	input[y]=temp;
}

int partitionArray(int input[], int start, int end) {
	// Write your code here
	int count=0;
	for(int i=start+1;i<=end;i++)
	{
		if(input[i]<input[start])
		 count++;
	}
    int x=start+count;
	swap(input,start,start+count);
	int i=start,j=end;

	while(i<x && j>x)
	{
		while(input[i]<=input[x])
		 i++;

		 while(input[j]>input[x])
		   j--;

		  if (i <x && j>x) {
            swap(input, i, j);
            i++;
            j--;
        } else {
            break;
        }

	}
	return x;
}

void quickSort(int input[], int start, int end) {
	if(start>=end)
	  return;

	  int k=partitionArray(input,start,end);
	  quickSort(input,start,k-1);
	  quickSort(input,k+1,end);
}

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void Swap(int input[],int a,int b)
{
 int temp=input[a];
    input[a]=input[b];
    input[b]=temp;
}
/*int partition(int input[],int si,int ei)
    {
        int pivot=input[si];
        int i=si,j=ei+1;
        while(i<j)
        {
            do
            {
                i++;
            }while(input[i]<=pivot);
            do
            {
                j--;
            }while(input[j]>pivot); 
                if(i<j)
                    Swap(input,i,j);
        }  
        Swap(input,si,j);
        return j;
    }
	*/int partition(int input[],int si,int ei)
    {
        int x=input[si],count=0;
        for(int i=si+1;i<=ei;i++)
        {
            if(input[i]<=x)
                count++;
        } 
        //int pvindex=si+count;
        Swap(input,si,si+count);
        int i=si,j=ei;
        //while(i<j)
        while(i<=si+count && j>si+count)
        {
            while(input[i]<=x)
                i++;
            while(input[j]>x)
                j--;
                if(i<si+count && j>si+count)
                  {
                      Swap(input,i,j);
                      i++;
                      j--;
                  }
        }
       
        return si+count;
    }
	void quickSort(int input[], int si, int ei)
	{
    		// your code goes here 
        if(si>=ei)
            return;
        int c=partition(input,si,ei);
        quickSort(input,si,c-1);
        quickSort(input,c+1,ei);
	}
	void quickSort(int input[], int size)
	{
    		quickSort(input, 0, size - 1);
	}

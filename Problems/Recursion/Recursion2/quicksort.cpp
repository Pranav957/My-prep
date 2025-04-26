#include <iostream>
using namespace std;
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


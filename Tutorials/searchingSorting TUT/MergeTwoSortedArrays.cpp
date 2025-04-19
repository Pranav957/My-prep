
#include <bits/stdc++.h>
using namespace std;
int* mergeTwoSortedArrays(int* arr1,int* arr2,int size1,int size2)
{
    int i=0,j=0,x=0;
    int *sortedArray=new int[20];
    while(i<size1 && j<size2)
    {
        if(arr1[i]<arr2[j])
        {
            sortedArray[x]=arr1[i];
            i++;x++;
        }
        else{
            sortedArray[x]=arr2[j];
            j++;
            x++;
        }
    }
    while(i<size1)
    {
        sortedArray[x]=arr1[i];
        i++;x++;
    }
    while(j<size2)
    {
        sortedArray[x]=arr2[j];
        j++;x++;
    }
    return sortedArray;
}

int main()
{
   
   
int arr1[]={10,14,18,27,32,45,48,52};
int arr2[]={4,6,17,21,35,38,45,49,54};

 int * arr3=mergeTwoSortedArrays(arr1,arr2,8,9);
 for(int i=0;i<17;i++)
   cout<<arr3[i]<<" ";
    return 0;
}

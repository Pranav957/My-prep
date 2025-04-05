#include<iostream>
// input - input array
// size - length of input array
// element - value to be searched
int binarySearch(int input[],int l,int h,int x)
{
    if(l>h)
        return -1;
    int mid=(l+h)/2;
    //cout<<mid<<" ";
    if(input[mid]==x)
        return mid;
    else if(x>input[mid])
        return binarySearch(input,mid+1,h,x);
    else
        return binarySearch(input,l,mid-1,x);
        
}  
int binarySearch(int input[], int size, int element) {
    // Write your code here
   int a= binarySearch( input,0,size-1,element);
    return a;
}

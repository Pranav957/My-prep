/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;

void kSortedArray(int input[],int n,int k) //maintain k elements heap , Every time k elements considered to get correct va;lue at particular index
{
    priority_queue<int> pq;      //space complexity O(k)
    int j=0;
    
    for(int i=0;i<k;i++)
    {
        pq.push(input[i]);
    }
    
    for(int i=k;i<n;i++)
    {
        input[j]=pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }
    
    while(!pq.empty())
    {
        input[j]=pq.top();
        pq.pop();
        j++;
    }
}

void kSortedArray1(int input[],int n,int k){ //space Complexity O(n);
    priority_queue<int> pq;
    
    for(int i=0;i<n;i++)
    {
        pq.push(input[i]);
    }
    int j=0;
    while(!pq.empty())
    {
        input[j]=pq.top();
        pq.pop();
        j++;
    }
}

int main()
{
    int arr[]={10,12,15,6,9};
    kSortedArray1(arr,5,3);
    
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" "  ; 
    }

    return 0;
}

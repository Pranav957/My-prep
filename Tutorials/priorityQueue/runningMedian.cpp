#include<queue>
#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;

    for(int i=0;i<n;i++){
        if(!maxHeap.empty() && arr[i]>maxHeap.top())
          minHeap.push(arr[i]);
         else
          maxHeap.push(arr[i]); 

           int x = abs((int)(maxHeap.size() - minHeap.size()));
    if(x>1)
    {
        if(maxHeap.size()>minHeap.size())
        {
            int top=maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
        else
        {
            int top=minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }
    }
    int totalSize=maxHeap.size()+minHeap.size();
    if(totalSize%2!=0)
    {
        if(maxHeap.size()>minHeap.size())
          cout<<maxHeap.top()<<" ";
        else
          cout<<minHeap.top()<<" ";  
    }
    else{
        int avg=(maxHeap.top()+minHeap.top())/2;
        cout<<avg<<" ";
    }
    }
  
}


<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  #include<queue>
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> Mheap;
    priority_queue<int,vector<int>,greater<int>> Lheap;
    Mheap.push(arr[0]);
    if(arr[0]!=0)
       cout<<arr[0]<<" ";
    for(int i=1;i<n;i++)
    {
         if(arr[i]<Mheap.top())
           Mheap.push(arr[i]);
         else
           Lheap.push(arr[i]);
        if(Mheap.size()>Lheap.size()+1)
         {
            int ele=Mheap.top();
            Mheap.pop();
            Lheap.push(ele);
         } 
         else if(Lheap.size()>Mheap.size()+1)
         {
             int ele=Lheap.top();
             Lheap.pop();
             Mheap.push(ele);
         }
         if(i%2!=0)
         {
             cout<<(Lheap.top()+Mheap.top())/2<<" ";
         }
         else 
         {
             if(Mheap.size()>Lheap.size())
               cout<<Mheap.top()<<" ";
             else
               cout<<Lheap.top()<<" ";  
         }
    }
}

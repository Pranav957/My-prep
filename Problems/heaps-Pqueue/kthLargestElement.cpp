#include<queue>
int kthLargest(int* arr, int n, int k) {
    // Write your code here
    priority_queue<int,vector<int>,greater<int>> p;

    for(int i=0;i<k;i++)
    {
        p.push(arr[i]);
    }
    for(int i=k;i<n;i++)
    {
        int tp=p.top();
        if(arr[i]>tp)
        {
            p.push(arr[i]);
            p.pop();
        }
    }
    return p.top();
}
/*#include<queue>
int kthLargest(int* arr, int n, int k) {
    // Write your code here
    priority_queue<int, vector<int>,less<int>> p;
    for(int i=0; i<n;i++)
    {
        p.push(arr[i]);
    }
    for(int i=0;i<k-1;i++)
    {
        p.pop();
    }
    return p.top();
}*/
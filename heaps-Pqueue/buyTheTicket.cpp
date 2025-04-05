#include<queue>
int buyTicket(int *arr, int n, int k) {
    // Write your code here
    queue<int> x;
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
    {
        x.push(i);
        pq.push(arr[i]);
    }
    int time=0;
    while(1)
    {
        int max=pq.top();
        int i=x.front();
        //cout<<arr[i]<<" "<<max<<" ";
         if(arr[i]==max)
         {
             x.pop();
             pq.pop();
            time+=1;
            if(i==k)
             return time;
         }
         else
       {
            x.pop();
         x.push(i);
       }
        
    }
}
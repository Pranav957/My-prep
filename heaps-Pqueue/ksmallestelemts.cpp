#include<queue>
vector<int> kSmallest(int arr[], int n, int k) {
    // Write your code here
  priority_queue <int> p;
  for(int i=0;i<k;i++)
  {
      p.push(arr[i]);
  }
  for(int i=k;i<n;i++)
  {
      int mac=p.top();
      if(arr[i]<mac)
      {
          p.pop();
          p.push(arr[i]);
      }
  }
  vector<int> v;
  for(int i=0;i<k;i++)
  {
      int tp=p.top();
      v.push_back(tp);
      p.pop();
  }
  return v;
}
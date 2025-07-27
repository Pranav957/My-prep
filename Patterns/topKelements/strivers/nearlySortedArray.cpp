class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<k;i++)
        {
            pq.push(arr[i]);
        }
        int j=0;
        
        for(int i=k;i<arr.size();i++)
        {
            pq.push(arr[i]);
          arr[j]=pq.top();
          pq.pop();
          j++;
          
        }
        
        while(!pq.empty())
         {
             arr[j]=pq.top();
             pq.pop();
             j++;
         } 
    }
};

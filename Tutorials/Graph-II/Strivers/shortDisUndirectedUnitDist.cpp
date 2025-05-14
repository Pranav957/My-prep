class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int N=adj.size();
     
     vector<int> distance(N,INT_MAX);
     distance[src]=0;
     queue<int> q;
     q.push(src);
     
     while(!q.empty())
     {
         int node=q.front();
         q.pop();
         
         for(auto it:adj[node])
         {
             if(distance[it]>1+distance[node])
             {
                 distance[it]=1+distance[node];
                 q.push(it);
             } 
         }
     }
     
     for(int i=0;i<distance.size();i++)
     {
         if(distance[i]==INT_MAX)
          distance[i]=-1;
     } 
      return distance;
        
    }
};

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        for(auto edge:edges)
        {
            adj[edge[0]].push_back({edge[1],edge[2]});
             adj[edge[1]].push_back({edge[0],edge[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        vector<int> distance(n+1,1e9);
        distance[1]=0;
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++)
          parent[i]=i;
        
        while(!pq.empty())
        {
            auto it=pq.top();
            int node=it.second;
            int dist=it.first;
            pq.pop();
            
            for(auto it: adj[node])
            {
               int adjNode=it.first;
               int edgwt=it.second;
               if(distance[adjNode]>dist+edgwt)
               {
                   distance[adjNode]=dist+edgwt;
                   parent[adjNode]=node;
                   pq.push({distance[adjNode],adjNode});
               }     
            }
        }
        
        if(distance[n]==1e9) return {-1};
        
        vector<int> path;
        int node=n;
        while(parent[node]!=node)
        {
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        path.push_back(distance[n]);
        reverse(path.begin(),path.end());
        return path;
    }

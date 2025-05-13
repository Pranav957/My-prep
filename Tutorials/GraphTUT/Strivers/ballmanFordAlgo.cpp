class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> distance(V,1e8);
        distance[src]=0;
        for(int i=0;i<V-1;i++)
        {
            for(auto edge:edges)
            {
                int u=edge[0];
                int v=edge[1];
                int w=edge[2];
                if(distance[u]!=1e8 && distance[u]+w<distance[v])
                {
                    distance[v]=distance[u]+w;
                }
            }
        }
        
        for(auto edge:edges)
            {
                int u=edge[0];
                int v=edge[1];
                int w=edge[2];
                if(distance[u]!=1e8 && distance[u]+w<distance[v])
                {
                   return {-1};
                }
            }
            
            return distance;
        
       
    }
};

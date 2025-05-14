class Solution {
  public:
    bool detectCycle(int sv, vector<bool>& visited, vector<int> adj[],int parent)
    {
        visited[sv]=true;
        
        for(auto it: adj[sv])
        {
            if(!visited[it])
            {
                if(detectCycle(it,visited,adj,sv))return true;
            }
            else if(it!=parent)
             return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
            for(auto it:edges)
            {
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
        
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(detectCycle(i,visited,adj,-1))
                  return true;
            }     
        }
        return false;
    }
};

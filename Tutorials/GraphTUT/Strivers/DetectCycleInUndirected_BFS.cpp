class Solution {
  public:
    bool detectCycle(int sv, vector<bool>& visited, vector<int> adj[])
    {
        queue<pair<int,int>> q;
        q.push({sv,-1});
        visited[sv]=true;
        
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto it:adj[node])
            {
                if(!visited[it])
                {
                 q.push({it,node});
                 visited[it]=true;
                }
                else if(it!=parent)
                  return true;
            }
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
                if(detectCycle(i,visited,adj))
                  return true;
            }     
        }
        return false;
    }

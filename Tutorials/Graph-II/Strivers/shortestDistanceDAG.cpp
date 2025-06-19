class Solution {
    
    private:
      void trvelDFS(vector<pair<int,int>> adj[],int sv, vector<bool>& visited,stack<int>& st)
      {
          visited[sv]=true;
          for(auto it : adj[sv])
          {
              if(!visited[it.first])
              {
                  trvelDFS(adj,it.first,visited,st);
              }
          }
          
          st.push(sv);
      }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> adj[V];
        for(int i=0;i<E;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        vector<bool> visited(V);
        
        stack<int> st;  //toposort is used as while cal dist for x we would jave calculated distances of all nodes which appears before x i.e. nodes from which we can reach x
        for(int i=0;i<V;i++) //O(M+N) time Complexity which is less than any other algo
        {
             if(!visited[i])
               trvelDFS(adj,i,visited,st);
        }
        
        vector<int> dist(V, INT_MAX);
         
        dist[0]=0;
        
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
             if (dist[node] != INT_MAX) { // Only relax if node is reachable
               for(auto it:adj[node])
            {
                int v=it.first;
                int wt=it.second;
                if(dist[v]>dist[node]+wt)
                {
                    dist[v]=dist[node]+wt;
                }
            }
             }
        }
        for(int i=0;i<V;i++)
         {
             if(dist[i]==INT_MAX)
              dist[i]=-1;
         }
         
         return dist;
          
    }

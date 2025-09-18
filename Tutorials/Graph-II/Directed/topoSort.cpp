class Solution { // linear ordering of vertices such a that there is an edge between u and v where u appears before v in that ordering
  public:
    void travelDFS(vector<vector<int>>& edges, vector<bool>& visited, stack<int>& st,int node )
    {
        visited[node]=true;
        
        for(auto it:edges[node])
        {
            if(!visited[it])
              travelDFS(edges,visited,st,it);
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }

        // code here
        vector<bool> visited(V);
        stack<int> st;
        vector<int> v;
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
             travelDFS(adj,visited,st,i);
        }
        
        while(!st.empty())
         {
              v.push_back(st.top());
          st.pop();
         }
         return v;
    }
};

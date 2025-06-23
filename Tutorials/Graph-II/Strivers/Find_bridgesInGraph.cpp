class Solution {
     int timer=1;

     void call_DFS( vector<vector<int>>& adj, int node, int parent,vector<bool>& visited, vector<int>& tin,vector<int> &low,vector<vector<int>> &bridges)
     {
         visited[node]=true;
         tin[node]=low[node]=timer;
         timer++;

         for(auto it : adj[node])
         {
            if(it==parent)continue;
            if(!visited[it])
            {
              call_DFS(adj,it,node,visited,tin,low,bridges);
              low[node]=min(low[node],low[it]);
              //node---it
              if(low[it]>tin[node])
              {
                bridges.push_back({node,it});
              }
            }
            else
            {
                low[node]=min(low[node],low[it]);
            }
         }

     }
   
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto edge:connections)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n,false);
        vector<int> tin(n);
        vector<int> low(n);
        vector<vector<int>> bridges;

        call_DFS(adj,0,-1,visited,tin,low,bridges);
        return bridges;
    }
};

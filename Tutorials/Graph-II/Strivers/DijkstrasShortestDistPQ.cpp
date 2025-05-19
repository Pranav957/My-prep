class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {     //ElogV
        // Code here
        vector<pair<int,int>> adj[V];
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
        }
        
        vector<int> dis(V,INT_MAX);
        dis[src]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        
        while(!pq.empty())
        {
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            
            for(auto it:adj[node])
            {
                int adjNode=it.first;
                int edgewt=it.second;
                if(dist+edgewt<dis[adjNode])
                {
                     dis[adjNode]=dist+edgewt;
                     pq.push({dis[adjNode],adjNode});
                }  
            }
        }
       return dis;   
    }
};
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<,UsingQueue<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  class Solution {                                                                   class Solution {
  public:                                                                               public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {                    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here                                                                        // Code here
        vector<pair<int,int>> adj[V];                                                       vector<pair<int,int>> adj[V];
        for(auto edge:edges)                                                                 for(auto edge:edges)
        {                                                                                     {
            int u=edge[0];                                                                       int u=edge[0];
            int v=edge[1];                                                                        int v=edge[1];
            int wt=edge[2];                                                                       int wt=edge[2];  
            adj[u].push_back({v,wt});                                                              adj[u].push_back({v,wt}); 
        }                                                                                      }
         
        vector<int> dis(V,INT_MAX);                                                           vector<int> dis(V,INT_MAX);
        dis[src]=0;                                                                            dis[src]=0;
        
        queue<pair<int,int>> pq;                                                             queue<int> pq;
        pq.push({0,src});                                                                    pq.push(src);
                                                                                              
        while(!pq.empty())                                                                    while(!pq.empty())
        {                                                                                    {
            int node=pq.front().second;                                                         int node=pq.front();
            int dist=pq.front().first;                                                          pq.pop();  
            pq.pop();                                                                         
                                                                                                 for(auto it:adj[node])
            for(auto it:adj[node])                                                               {
            {                                                                                       int adjNode=it.first;
                int adjNode=it.first;                                                                int edgewt=it.second;
                int edgewt=it.second;                                                               if(dis[node]+edgewt<dis[adjNode])                                   
                if(dist+edgewt<dis[adjNode])                                                        {
                {                                                                                     dis[adjNode]=dis[node]+edgewt;  
                     dis[adjNode]=dist+edgewt;                                                          pq.push(adjNode);
                     pq.push({dis[adjNode],adjNode});                                                } 
                 }                                                                                 }  
            }                                                                                   }
        }                                                                                     return dis;
       return dis;                                                                          } 
    }                                                                                    };
};                                                                                      

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<UsingSet<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>> adj[V];
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
        }
        
        vector<int> dis(V,INT_MAX);
        dis[src]=0;
        
        set<pair<int,int>> st;
        st.insert({0,src});
        
        while(!st.empty())
        {
            auto it=st.begin();
            int node=it->second;
            int dist=it->first;
            st.erase(it);
            
            for(auto it:adj[node])
            {
                int adjNode=it.first;
                int edgewt=it.second;
                if(dist+edgewt<dis[adjNode])
                {
                    if(dis[adjNode]!=INT_MAX)
                        st.erase({dis[adjNode],adjNode});
                     dis[adjNode]=dist+edgewt;
                     st.insert({dis[adjNode],adjNode});
                }  
            }
        }
       return dis;   
    }

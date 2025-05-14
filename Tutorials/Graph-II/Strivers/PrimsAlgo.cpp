class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> visited(V,false);
        pq.push({0,0});
        int sum=0;
        
        while(!pq.empty())
        {
            auto it=pq.top();
            int node=it.second;
            int wt=it.first;
            pq.pop();
            
            if(visited[node])continue;
            
            visited[node]=true;
            sum+=wt;
            for(auto it:adj[node])
            {
                int adjNode=it[0];
                int edgwt=it[1];
                
                if(!visited[adjNode])
                {
                    pq.push({edgwt,adjNode});
                }
            }
             
        }
        return sum;
        
    }
};

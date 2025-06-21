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
          // if parent is not -1 then ans.push({parent,node})
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
//MST-> a Tree with n nodes and n-1 edges and all the nodes rae reachable from each other
//first push [0,0,-1]-[wt,node,parent]  in pq 
//get the top and mark it as visited and add wt into sum and add the edge into ans array if parent is not -1
//check adjacent nodes which are unvisited and push them into the array
//Intution->GREEDY->everytime we are pulling min wt edge from pqand adding it into the ans and marking node as visited(i.e. node is part of mst)

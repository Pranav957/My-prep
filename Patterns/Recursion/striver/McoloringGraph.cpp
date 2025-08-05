class Solution {
  public:
   bool isSafe(int node, vector<int>& color,vector<vector<int>>& adj,int n,int x)
   {
       for(auto it : adj[node])
       {
           if(color[it]==x)
            return false;
       }
       return true;
   }
    bool solve(int node,vector<int>& color,int n,int m,vector<vector<int>>&adj)
    {
        if(node==n)
         return true;
         
         for(int i=1;i<=m;i++)
         {
            if(isSafe(node,color,adj,n,i))
            {
                color[node]=i;
                if(solve(node+1,color,n,m,adj))return true;
                color[node]=0;
            }
         }
         return false;
    }
    
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>> adj(v);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
      vector<int> color(v,0);
      return solve(0,color,v,m,adj);
    }
};

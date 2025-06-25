// User function Template for C++

class Solution {
    int timer=1;
    void dfsTraversal(vector<int> adj[],int node,int parent,int tin[],int low[],vector<bool>& visited,vector<int>& mark)
    {
        visited[node]=true;
        tin[node]=low[node]=timer;
        timer++;
        int child=0;
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                dfsTraversal(adj,it,node,tin,low,visited,mark);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node] && parent!=-1)   // if you are not able to reach before me(node)
                {
                    mark[node]=1;
                }
                child++;
            }
            else{
                low[node]=min(low[node],tin[it]);  // we came by that path (it) if its removed we cant go before it
            }
        }
        if(child>1 && parent==-1)
           mark[node]=1;
          
    }
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        int n=V;
        vector<bool> visited(n,false);
        int tin[n];
        int low[n];
        vector<int> mark(n,0);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
              dfsTraversal(adj,i,-1,tin,low,visited,mark);
        }
        
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(mark[i]==1)
              ans.push_back(i);
        }
        
        if(ans.size()==0)
          return {-1};
        
        return ans;  
    }
    
};

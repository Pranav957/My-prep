class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
                vector<vector<int>> adj(V);
    for (auto& edge : prerequisites) {
        adj[edge[0]].push_back(edge[1]);
    }
        // code here
        int* indegree=new int[V];
        for(int i=0;i<V;i++)
          indegree[i]=0;
        
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
              indegree[it]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
             q.push(i);
        }
        
        int cnt=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
         cnt++;
            
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                  q.push(it);
            }
            
        }
        if(cnt==V)return true;
        return false;
        
    }
};

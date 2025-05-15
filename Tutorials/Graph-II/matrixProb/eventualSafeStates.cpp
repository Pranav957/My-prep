class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       const int N=graph.size();
        vector<vector<int>> adj(N);
        vector<int> indegree(N);
        for(int i=0;i<N;i++)
        {
            for(auto it:graph[i])
            {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;

        for(int i=0;i<N;i++)
        {
            if(indegree[i]==0)
             q.push(i);
        }
        vector<int> safe;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            safe.push_back(node);
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                 q.push(it);
            }
        }
        sort(safe.begin(),safe.end());
      return safe;
    }
};

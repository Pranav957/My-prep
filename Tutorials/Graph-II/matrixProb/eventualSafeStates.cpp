class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) { // if cycle is preset then nodes in cycle will have path which does not end at terminal so 
       const int N=graph.size();                                //topo sort will give only nodes which ends at terminal as indegree of cycle nodes will never becomes 0 so wont be updated in queue
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

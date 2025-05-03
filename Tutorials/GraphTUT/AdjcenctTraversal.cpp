/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

    void travelDfs(int v,vector<int> adj[],vector<int> &dfs, vector<bool>& visited,int sv)
    {
        dfs.push_back(sv);
        visited[sv]=true;

        for(auto neighbour: adj[sv])
        {
            if(!visited[neighbour])
             travelDfs(v,adj,dfs,visited,neighbour);
        }
  
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       vector<int> dfs;
       vector<bool>visited(V);
       travelDfs(V,adj,dfs,visited,0);
        return dfs;

    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        vector<bool> visited(V);

        queue<int> pendingNodes;

        pendingNodes.push(0);
        visited[0]=true;

        while(!pendingNodes.empty())
        {
          int front=pendingNodes.front();
          pendingNodes.pop();
            bfs.push_back(front);
           for(int neighbour:adj[front])
           {
             if(!visited[neighbour])
             {
              pendingNodes.push(neighbour);
              visited[neighbour]=true;
             }
           }
        }
        
        return bfs;

    }



int main()
{
    vector<int> adj[5]={{2,3,1},{0},{0,4},{2}};
    
    vector<int> res=dfsOfGraph(5,adj);
    vector<int>res1=bfsOfGraph(2,adj);
    
    for(int i=0;i<res.size();i++)
      cout<<res[i]<<" ";
      
      cout<<endl;
      
       for(int i=0;i<res.size();i++)
      cout<<res1[i]<<" ";
    
    std::cout<<"Hello World";

    return 0;
}

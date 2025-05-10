/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool checkCycle(vector<vector<int>>& edges, int sv, vector<int>& vis, vector<int>& pathVis) {
        vis[sv] = 1;
        pathVis[sv] = 1;

        for (int neighbor : edges[sv]) {
            if (!vis[neighbor]) {
                if (checkCycle(edges, neighbor, vis, pathVis))
                    return true;
            } else if (pathVis[neighbor]) {
                return true;
            }
        }

        pathVis[sv] = 0;
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (checkCycle(edges, i, vis, pathVis))
                    return true;
            }
        }

        return false;
    }
};
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<**********************************************<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
class Solution {
    private:
     bool checkCycle(int v,vector<vector<int>>& edges,int sv,int vis[], int pathVis[])
     {
         vis[sv]=1;
         pathVis[sv]=1;
         
         for(auto neighbour: edges[sv])
         {
             if(!vis[neighbour])
             {
                 bool result=checkCycle(v,edges,neighbour,vis,pathVis);
                 if(result==true)
                  return true;
             }
             else if(pathVis[neighbour])
              return  true;
             
         }
         
         pathVis[sv]=0;
         return false;
     }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        int vis[V]={0};
        int pathVis[V]={0};
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                 if( checkCycle(V,edges,i,vis,pathVis))return true;
            }
        }
        return false;
    }
};




int main()
{
    Solution obj;
    int V = 5;
    vector<vector<int>> edges(V);
    edges[3].push_back(0);
    edges[4].push_back(2);
    edges[1].push_back(2);

    cout << (obj.isCyclic(V, edges) ? "Cycle detected\n" : "No cycle\n");
    return 0;

}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  class Solution {
private:

   vector<vector<int>> buildAdjList(int V, vector<vector<int>>& edgePairs) {
    vector<vector<int>> adj(V);
    for (auto& e : edgePairs) {
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
    }
    return adj;
}

    bool checkCycle(vector<vector<int>>& edges, int sv, vector<int>& vis, vector<int>& pathVis) {
        vis[sv] = 1;
        pathVis[sv] = 1;

        for (int neighbor : edges[sv]) {
            if (!vis[neighbor]) {
                if (checkCycle(edges, neighbor, vis, pathVis))
                    return true;
            } else if (pathVis[neighbor]) {
                return true;
            }
        }

        pathVis[sv] = 0;
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
         vector<vector<int>> adj = buildAdjList(V, edges);
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (checkCycle(adj, i, vis, pathVis))
                    return true;
            }
        }

        return false;
    }
};

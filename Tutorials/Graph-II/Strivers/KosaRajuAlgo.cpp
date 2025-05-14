/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
// to find strongly connected components

#include <bits/stdc++.h>
using namespace std;



void travelDFS(vector<int> adj[], int sv, vector<bool>& visited,stack<int>& st)
{
    visited[sv]=true;
    
    for(auto it: adj[sv])
    {
        if(!visited[it])
         travelDFS(adj,it,visited,st);
    }
    st.push(sv);
}

void travelDFSREV(vector<int> adj[], int sv, vector<bool>& visited)
{
    visited[sv]=true;
    cout<<sv<<" ";
    
    for(auto it: adj[sv])
    {
        if(!visited[it])
         travelDFSREV(adj,it,visited);
    }
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> st;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            travelDFS(adj, i, visited, st);
    }

    // Reverse the graph
    vector<int> revAdj[n];
    for (int u = 0; u < n; u++) {
        visited[u] = false;  // Reset visited for second DFS
        for (auto v : adj[u]) {
            revAdj[v].push_back(u);  // Reverse edge
        }
    }

    // Second DFS on reversed graph
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            travelDFSREV(revAdj, node, visited);
            cout << endl;
        }
    }

    return 0;
}

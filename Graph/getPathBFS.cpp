#include <bits/stdc++.h>
using namespace std;
vector<int>* get_bfs_path(int ** edge, int n, bool* visited,int sv, int ev)
{
   queue<int> pendingVertex;
   pendingVertex.push(sv);
   visited[sv]=true;

   unordered_map<int,int> um;

   while(!pendingVertex.empty())
   {
       int front=pendingVertex.front();
       pendingVertex.pop();
       if(front==ev)
       {
          vector<int>* v=new vector<int>();
          v->push_back(front);

          int curr=ev;
          while(curr!=sv)
          {
              v->push_back(um[curr]);
              curr=um[curr];
          }
          return v;
          
       }
       for(int i=0;i<n;i++)
       {
           if(edge[front][i]==1 && !visited[i])
           {
               pendingVertex.push(i);
               visited[i]=true;
               um[i]=front;
           }
       }

   }
   return NULL;
}

int main() {
    // Write your code here
    int n,e;
   cin >> n>> e;
    int ** edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for (int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++)
    {
        int f,s;
        cin >> f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    
    bool* visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }

   int v1,v2;
   cin >> v1>>v2;
    vector<int>* path=get_bfs_path(edges,n,visited,v1,v2);
    if(path==NULL)
      return 0;
    for(int i=0;i<path->size();i++)
    {
        cout<<path->at(i)<<" ";
    }
    delete [] visited;
    for(int i=0;i<n;i++)
    {
        delete []edges[i];
    }
    delete[] edges;
}
#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
vector<int> *Find_path_BFS(int **arr, int n, int sv, int ev, bool *visited) {
     queue<int> pendingVertices;
     pendingVertices.push(sv);
     visited[sv]=true;
     unordered_map<int,int>  mp;
     while(!pendingVertices.empty())
     {
         int vertex=pendingVertices.front();
         pendingVertices.pop();
        if(vertex==ev)
        {
          vector<int>* v=new vector<int>();
          v->push_back(ev);
          int curr=ev;
          while(curr!=sv)
          {
             v->push_back(mp[curr]);
             curr=mp[curr];
          }
          return v;
        }
        for(int i=0;i<n;i++)
        {
           if(arr[vertex][i]==1 && !visited[i])
           {
              pendingVertices.push(i);
              visited[i]=true;
              mp[i]=vertex;
           }
        }
     }
     return NULL;
}
int main() {
    // Write your code here
    int n, e;
    cin >>n >>e;
    int** arr=new int*[n];
    for(int i=0;i<n;i++)
    {
      arr[i]=new int[n];
      for(int j=0;j<n;j++)
        arr[i][j]=0;
    }
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin >> a>>b;
        arr[a][b]=1;
        arr[b][a]=1;
    }
    int sv,ev;
    cin >> sv >> ev;
    bool* visited=new bool[n];
    for(int i=0;i<n;i++)
      visited[i]=false;
     vector<int>* vect=  Find_path_BFS(arr, n, sv,  ev, visited);
     if(vect!=NULL)
     {
         for(int i=0;i<vect->size();i++)
         {
             cout<<vect->at(i)<<" ";
         }
     }
}

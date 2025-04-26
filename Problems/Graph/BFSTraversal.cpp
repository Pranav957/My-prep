#include <iostream>
#include<queue>
using namespace std;
void print(int** graph,int n,int sv,bool* visited)
{
   queue<int> q;
      q.push(sv);
      visited[sv]=true;
   while(!q.empty())
   {
      int vertex=q.front();
          q.pop();
         cout<<vertex<<" ";
      
       for(int i=0;i<n;i++)
       {
           
           if(graph[vertex][i]==1 && visited[i]==false)
            {
             q.push(i);
             visited[i] = true;
            }
       }
   }
}
int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    if(v==0)
     return 0;
    int** graph=new int*[v];
    for(int i=0;i<v;i++)
    {
        graph[i]=new int[v];
        for(int j=0;j<v;j++)
          graph[i][j]=0;
    }
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin >> f >>s;
        graph[f][s]=1;
        graph[s][f]=1;
    }
    bool* visisted=new bool[v];
    for(int i=0;i<v;i++)
     visisted[i]=false;
     print(graph,v,0,visisted);
     for (int i = 1; i < v; i++) {
       if (visisted[i] == false) 
       print(graph, v, i, visisted);
     }
}
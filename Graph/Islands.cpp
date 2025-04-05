#include <iostream>
using namespace std;
void findConnectedIslans(int** graph, int n, bool* visited,int sv)
{
   visited[sv]=true;
   for(int i=0;i<n;i++)
   {
       if(graph[sv][i]==1 && !visited[i])
       {
           findConnectedIslans(graph,n,visited,i);
       }
   }
}
int main() {
    // Write your code here
    int n , e;
    cin >> n>>e;

    int** graph=new int*[n];
    for(int i=0;i<n;i++)
    {
        graph[i]=new int[n];
        for(int j=0;j<n;j++)
          graph[i][j]=0;
    }

    for(int i=0;i<e;i++)
    {
      int f,s;
      cin >>f>>s;
      graph[f][s]=1;
      graph[s][f]=1;
    }

    bool* visited=new bool[n];
    for(int i=0;i<n;i++)
      visited[i]=false;
  int count=0;
  for(int i=0;i<n;i++)
  {
    if(visited[i]==false)
    {
       findConnectedIslans(graph,n,visited,i);
       count++;
    } 
     
  }
    cout<<count<<' ';  
}
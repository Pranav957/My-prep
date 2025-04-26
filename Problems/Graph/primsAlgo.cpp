#include <iostream>
#include<climits>
using namespace std;

int find_unvisited(int** edges,int n, bool* visited,int* weights)
{
    int unvisited=0;
   int minweight=INT_MAX;
    for(int i=0;i<n;i++)
    {
          if(!visited[i] && weights[i]<minweight)
            {
                   unvisited=i;
                   minweight=weights[i];
            }
    }
    return unvisited;
}
void fins_MST(int ** edges, int n,bool * visited, int * weights,int* parent)
{
    int count=0;
   while(count!=n)
   {
        int unvisitedV=find_unvisited(edges,n,visited,weights);
    visited[unvisitedV]=true;
     count++;
    for(int i=0;i<n;i++)
    {
        if(edges[unvisitedV][i]>0 && !visited[i] && edges[unvisitedV][i]<weights[i])
         {
              weights[i]=edges[unvisitedV][i];
          parent[i]=unvisitedV;
         }
    }
   }
}

int main() {
    // Write your code here
    int n,e;
    cin >> n >> e;

    int ** edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
          edges[i][j]=-1;
    }

    for(int i=0;i<e;i++)
    {
        int f,s,w;
        cin >> f >> s>>w;
        edges[f][s]=w;
        edges[s][f]=w;
    }
    bool * visited=new bool[n];
      int* weights=new int[n];
      int* parent=new int[n];
      
      for(int i=0;i<n;i++)
     {
          visited[i]=false;
          weights[i]=INT_MAX;
          parent[i]=-1;
     }
     weights[0]=0;
      fins_MST(edges,n,visited,weights,parent);
    for(int i=0;i<n;i++)
      {
          if(parent[i]!=-1)
         {
              int s=i,d=parent[i],w=edges[s][d];
              if(s<d)
               cout<<s<<" "<<d<<" "<<w<<endl;
              else
                  cout<<d<<" "<<s<<" "<<w<<endl;
         }
      }
    delete [] visited;
    for(int i=0;i<n;i++)
     delete [] edges[i];

     delete []edges;

}
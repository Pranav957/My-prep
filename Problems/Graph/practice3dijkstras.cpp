/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int findMinUnvisitedVertex(int* dist, bool* visited,int n)
{
    int minDistance=INT_MAX;
    int index;
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && dist[i]<minDistance)
        {
            minDistance=dist[i];
            index=i;
        }
    }
    return index;
}

void PrimsAlgo(int** edges,bool* visited, int* dist,int n)
{
    
    int countVisited=0;
    
    while(countVisited!=n)
    {
        int vertex=findMinUnvisitedVertex(dist,visited,n);
    visited[vertex]=true;
    countVisited++;
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && edges[vertex][i]>=1 && dist[vertex]+edges[vertex][i] < dist[i] )
        {
            dist[i]=edges[vertex][i]+dist[vertex];
        }
    }
    }
    
    
}

int main()
{
    int n, e;
    cin >> n>> e;
    
    int** edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    
    for(int i=0;i<e;i++)
    {
        int first, second,wt;
        cin >> first >> second>> wt;
        
        edges[first][second]=wt;
        edges[second][first]=wt;
        
    }
    
    bool* visited=new bool[n];
     
     int* dist=new int[n];
     
     for(int i=0;i<n;i++)
     {
         visited[i]=false;
         dist[i]=INT_MAX;
     }
     
     dist[0]=0;
     
     PrimsAlgo(edges,visited ,dist,n);
     
     for(int i=0;i<n;i++)
     {
         cout<<i<<" "<<dist[i]<<endl;
     }
     
     delete [] visited;
     delete [] dist;
     
     for(int i=0;i<n;i++)
      delete [] edges[i];
      
      delete[] edges;
    
    return 0;
    
}

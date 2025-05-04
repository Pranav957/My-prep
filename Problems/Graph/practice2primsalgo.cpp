/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int findMinUnvisitedVertex(int* weight, bool* visited,int n)
{
    int minWeight=INT_MAX;
    int index;
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && weight[i]<minWeight)
        {
            minWeight=weight[i];
            index=i;
        }
    }
    return index;
}

void PrimsAlgo(int** edges,bool* visited,int* parent, int* weight,int n)
{
    
    int countVisited=0;
    
    while(countVisited!=n)
    {
        int vertex=findMinUnvisitedVertex(weight,visited,n);
    visited[vertex]=true;
    countVisited++;
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && edges[vertex][i]>=1 && edges[vertex][i] < weight[i] )
        {
            weight[i]=edges[vertex][i];
            parent[i]=vertex;
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
     
     int * parent=new int[n];
     
     int* weight=new int[n];
     
     for(int i=0;i<n;i++)
     {
         visited[i]=false;
         parent[i]=-1;
         weight[i]=INT_MAX;
     }
     
     weight[0]=0;
     
     PrimsAlgo(edges,visited,parent ,weight,n);
     
     for(int i=0;i<n;i++)
     {
         if(parent[i]==-1)
           continue;
           
           int source=i,dest=parent[i], wt=edges[source][dest];
           
           cout<<source<<" "<<dest<<" "<<wt<<endl;
     }
     
     delete [] visited;
     delete [] parent;
     delete [] weight;
     
     for(int i=0;i<n;i++)
      delete [] edges[i];
      
      delete[] edges;
    
    return 0;
    
}

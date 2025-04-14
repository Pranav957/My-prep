/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void printDFS(int ** edges, int n,bool* visited, int sv)
{
    cout<<sv<<" ";
    visited[sv]=true;
    
    for(int i=0;i<n;i++)
    {
        if(edges[sv][i]==1 && !visited[i])
           printDFS(edges,n,visited,i);
    }
}

void printBFS(int ** edges, int n,bool* visited, int sv)
{
   queue<int> pendingVertices;
   pendingVertices.push(sv);
   visited[sv]=true;
   while(!pendingVertices.empty())
   {
      int vertex=pendingVertices.front();
      pendingVertices.pop();
      cout<<vertex<<" ";
      for(int i=0;i<n;i++)
      {
        if(edges[vertex][i]==1 && !visited[i])
         {
           pendingVertices.push(i);
           visited[i]=true;
         }  
      }

   }
}

bool Haspath(int** edges, int n,int st,int ed,bool* visited)
{
     visited[st]=true;
     if(st==ed)
      return true;

     for(int i=0;i<n;i++)
     {
         if(edges[st][i]==1)
         {
          //  if(i==ed)
          //    return true;
             if(!visited[i])
             {
                bool ans=Haspath(edges,n,i,ed,visited);
                if(ans)
                 return true;
             } 
         }
     }
     return false;
}


int main()
{
    int n , e;
    cin >> n >> e;

    if(n==0)
      return 0;
    
    int** edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
          edges[i][j]=0;
    }
    
    for(int i=0;i<e;i++)
    {
        int first,second;
        cin >> first >> second;
        edges[first][second]=1;
        edges[second][first]=1;
    }
    
    bool* visited=new bool[n];
    for(int i=0;i<n;i++)
       visited[i]=false;
     
     printBFS(edges,n,visited,0);

     for(int i=1;i<n;i++)
     {
       if(visited[i]==false)
        printBFS(edges,n,visited,i);
     }
     
     delete [] visited;
     for(int i=0;i<n;i++)
       delete [] edges[i];
       
       delete [] edges;
       

    return 0;
}

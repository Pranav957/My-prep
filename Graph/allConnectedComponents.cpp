#include <bits/stdc++.h>
using namespace std;

void ConnectedComponents(int** edges, int n , bool * visited,int sv,vector<int>& v)
{
    v.push_back(sv);
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(edges[sv][i]==1 && !visited[i])
       {
           ConnectedComponents(edges,n,visited,i,v);
       }
    }
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
     for(int j=0;j<n;j++)
    {
       if( visited[j]==false)
        {
            vector<int> v;
             ConnectedComponents(edges,n,visited,j,v);
            sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++)
              cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    
}

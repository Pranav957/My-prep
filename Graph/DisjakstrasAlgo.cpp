#include <iostream>
#include<climits>
using namespace std;
int find_closest_vertex(int n,bool* visited, int* distance)
{
    int minDstance=INT_MAX;
    int vertex=-1;
    for(int i=0;i<n;i++)
    {
        bool x=distance[i]<minDstance;
        // cout<< distance[i]<<" "<<visited[i]<<endl;
        if(!visited[i] && distance[i]<minDstance)
        {
            minDstance=distance[i];
            vertex=i;
        }
    }
    cout<<vertex<<" "<<minDstance<<endl;
    return vertex;
}

void shortestPath(int** edge, int n,bool* visited, int* distance)
{
    int countVisited=0;
    while(countVisited!=n)
    {
        int vertex=find_closest_vertex(n,visited,distance);
        cout<<vertex<<endl;
        if(vertex==-1)
          return;
        visited[vertex]=true;
        countVisited++;
        for(int i=0;i<n;i++)
        {
            if(!visited && edge[vertex][i]!=0)
            {
                cout<<distance[i]<<" "<<distance[vertex]+edge[vertex][i]<<endl;
                if(distance[i]>distance[vertex]+edge[vertex][i])
                   distance[i]=distance[vertex]+edge[vertex][i];
            }
        }
    }
}
int main() {
    // Write your code here
    int n,e;
    cin >> n>>e;

    int** edge=new int*[n];
    for(int i=0;i<n;i++)
    {
        edge[i]=new int[n];
        for(int j =0;j<n;j++)
        {
            edge[i][j]=0;
        }
    }

    for(int i=0;i<e;i++)
    {
        int f,s,w;
        cin >> f>>s>>w;
        edge[f][s]=w;
        edge[s][f]=w;
    }

    bool* visited=new bool[n];
    int * distance=new int[n];

    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    shortestPath(edge,n,visited,distance);
    //  for(int i=0;i<n;i++)
    //   cout<<i<<" "<<distance[i]<<endl;
}
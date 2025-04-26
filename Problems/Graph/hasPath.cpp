#include <iostream>
using namespace std;
bool Haspath(int** G,int n,int st,int ed,bool visited[])
{
   
    visited[st]=true;
    for(int i=0;i<n;i++)
    {
       if(G[st][i]==1 )
       {
          if(i==ed)
             return true;
          if(visited[i])
              continue;
            bool ans= Haspath(G,n,i,ed,visited); 
            if(ans)
             return ans; 
       }
    }
    //
    return false;
}
int main() {
    // Write your code here
    
    int n=0,e=0;
   cin>>n>>e;
    //cout << "hi";
    int** G=new int*[n];
    //cout << "hi";
    for(int i=0;i<n;i++)
    {
        G[i]=new int[n];
        for(int j=0;j<n;j++)
          G[i][j]=0;
    }
    //cout << "hi";
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin >> a >> b;
        G[a][b]=1;
        G[b][a]=1;
    }
    int st, ed;
    cin >> st >> ed;
    
    bool* visited=new bool[n];
    for(int i=0;i<n;i++)
       visited[i]=false;
     bool ans=Haspath(G,n,st,ed,visited); 
     if(ans)
       cout<<"true";
     else
       cout<<"false";   
}
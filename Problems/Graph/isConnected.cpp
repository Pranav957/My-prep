#include <iostream>
using namespace std;
void Traversal_DFS(int** arr,int n, bool* visited, int sv)
{
    visited[sv]=true;
    for(int i=0;i<n;i++)
     {
         if(arr[sv][i]==1 && visited[i]==false)
           Traversal_DFS(arr,n,visited,i);
     } 
}
int main() {
    // Write your code here
    int n, e;
    cin >> n >> e;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++) {
      arr[i] = new int[n];
      for (int j = 0; j < n; j++)
        arr[i][j] = 0;
    }
    for (int i = 0; i < e; i++) {
      int a, b;
      cin >> a >> b;
      arr[a][b] = 1;
      arr[b][a] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
      visited[i] = false;
      Traversal_DFS(arr,n,visited,0);
      for(int i=0;i<n;i++)
      {
          if(!visited[i])
           {
            cout << "false";
            return 0;
           } 
      }
      cout<<"true";
      return 0;
}
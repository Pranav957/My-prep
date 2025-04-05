#include <iostream>
using namespace std;

int main() {
    // Write your code here
    int n, e;
    cin >> n >> e;
   
    int **graph = new int *[n];
    for (int i = 0; i < n; i++) {
      graph[i] = new int[n];
      for (int j = 0; j < n; j++)
        graph[i][j] = 0;
    }
    for (int i = 0; i < e; i++) {
      int f, s;
      cin >> f >> s;
      graph[f][s] = 1;
      graph[s][f] = 1;
    }
    
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
              continue;
            if(graph[i][j]==1)
            {
                for(int k=0;k<n;k++)
                {
                    if(k==i || k==j)
                      continue;
                    if(graph[j][k]==1)
                    {
                        if(graph[i][k]==1)
                        count+=1;
                    }  
                }
            }  
        }
    }
    int ans=count/6;
    cout<<ans<<" ";
    return 0;
}
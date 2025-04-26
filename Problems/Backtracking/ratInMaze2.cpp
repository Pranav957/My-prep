#include <bits/stdc++.h> 
void searchMaze(vector < vector < int >> & arr, int n,int r ,int c, string str,vector<string>& v,vector<vector<bool>>& visited)
{
    
    
    if(r>=n || r<0 || c<0 ||c>=n || arr[r][c]==0 || visited[r][c] )
      return;
    
    if(r==n-1 && c==n-1)
    {
        v.push_back(str);
        return;
    }

    visited[r][c]=true;
    searchMaze(arr,n,r+1,c,str+"D",v,visited);
    searchMaze(arr,n,r,c+1,str+"R",v,visited);
    searchMaze(arr,n,r-1,c,str+"U",v,visited);
    searchMaze(arr,n,r,c-1,str+"L",v,visited);

    visited[r][c]=false;
      
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> v;
    if (arr[0][0] == 0)
        return v;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    searchMaze(arr,n,0,0,"",v,visited);
    return v;
}

bool helper_has_Cycle(vector<vector<char>> &board,int n, int m,int i, int j, bool** visited,char color,int parent_i,int parent_j)
{
  visited[i][j] = true;
  int neighbours[4][2] = {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
  for (int k = 0; k < 4; k++) {
    int ni = neighbours[k][0], nj = neighbours[k][1];
    if (ni < 0 || ni >= n || nj < 0 || nj >= m)
      continue; // Out of bounds
    if (ni == parent_i && nj == parent_j)
      continue; // Skip parent
    if (board[ni][nj] != color)
      continue; // Different color
    if (visited[ni][nj])
      return true; // Cycle found
    if (helper_has_Cycle(board,n,m,ni,nj,visited,color,i,j))
      return true;
  }
  return false;
} 
bool hasCycle(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    bool** visited=new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new bool[m];
        for(int j=0;j<m;j++)
           visited[i][j]=false;
    }
   
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
         {
          if (visited[i][j] == false)
            {
            char ch = board[i][j];
            bool ans = helper_has_Cycle(board, n, m, i, j, visited, ch, -1, -1);
            if(ans) return true;
            }
         }
    }
    return false;
}
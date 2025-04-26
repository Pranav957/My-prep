bool Helper_haspath(vector<vector<char>> & board,int n,int m,int i,int j,bool** visited,string str)
{
    if(str.length()==0)
    {
      //cout << "hi";
      return true;
    }
     if(i<0 || i>=n || j<0 || j>=m)
       return false;
    if(visited[i][j]==true)
       return false;
     if(board[i][j]==str[0])
     {
        //cout<<str[0];
         visited[i][j]=true;
         bool ans;
         ans=Helper_haspath(board,n,m,i-1,j,visited,str.substr(1));
         if(ans)
           return true;
         ans = Helper_haspath(board, n, m, i+1, j, visited, str.substr(1));
         if (ans)
           return true;
         ans = Helper_haspath(board, n, m, i, j+1, visited, str.substr(1));
         if (ans)
           return true;
           
         ans = Helper_haspath(board, n, m, i,j-1, visited, str.substr(1));
         if (ans)
           return true;
         ans = Helper_haspath(board, n, m, i-1, j-1, visited, str.substr(1));
         if (ans)
           return true;
         ans = Helper_haspath(board, n, m, i+1, j+1, visited, str.substr(1));
         if (ans)
           return true;
         ans = Helper_haspath(board, n, m, i+1, j-1, visited, str.substr(1));
         if (ans)
           return true;
         ans = Helper_haspath(board, n, m, i-1,j+1, visited, str.substr(1));
         if (ans)
           return true;
         
     }   
     visited[i][j]=false;
     
     return false;     

}
bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    bool** visited=new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new bool[m];
        for(int j=0;j<m;j++)
           visited[i][j]=false;
    }
    string str="CODINGNINJA";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]=='C')
            {
              
              bool ans= Helper_haspath(board, n, m, i, j, visited, str);
              if(ans)
               return true;
            }
        }
    }
    return false;
}
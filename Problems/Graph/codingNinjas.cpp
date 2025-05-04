
bool DFSCALL(vector<vector<char>> & board,int currX,int currY,string word,int strindex, int** visited,int n,int m)
{
  if(strindex==word.length())
     return true;

     visited[currX][currY]=1;

     int diffx[8]={-1,-1,-1,0,0,1,1,1};
     int diffy[8]={-1,0,1,-1,1,-1,0,1};

     bool found=false;

     for(int i=0;i<8;i++)
     {
            int newx=currX+diffx[i];
            int newy=currY+diffy[i];
          if(newx>=0 && newx<n && newy>=0 && newy<m)
          {
            if(board[newx][newy]==word[strindex] && visited[newx][newy]==0)
            {
              found = DFSCALL(board,newx,newy,word,strindex+1,visited,n,m);
              if(found)
               return true;
            }
          }
     }
     visited[currX][currY]=0;
     return found;
}



bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
     string  word="CODINGNINJA";
     bool flag=false;
     int** visited= new int*[n];
     for(int i=0;i<n;i++)
     {
       visited[i]=new int[m];
       for(int j=0;j<m;j++)
        visited[i][j]=0;
     }

     for(int i=0;i<n;i++)
     {
       for(int j=0;j<m;j++)
       {
         if(board[i][j]==word[0])
           flag=DFSCALL(board,i,j,word,1,visited,n,m);
           if(flag)
            return true;
       }
     }
     return false;
}


<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
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

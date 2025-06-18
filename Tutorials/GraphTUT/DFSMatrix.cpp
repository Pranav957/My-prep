

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
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  bool findCycle(vector<vector<char>>& board,int currX, int currY,  vector<vector<bool>> &visited, char ch,int n,int m,int parent_x,int parent_y )
{
    visited[currX][currY]=true;

    int diffX[4]={-1, 0, 1,0};
    int diffY[4]={0,1,0,-1};


    for(int i=0;i<4;i++)
    {
        int newX=currX+diffX[i];
        int newY=currY+diffY[i];

        if(newX<0 || newX>=n || newY<0 || newY>=m)
          continue;

        if(board[newX][newY]!=ch)
         continue;

        if(newX==parent_x && newY==parent_y)
          continue;

         if( visited[newX][newY])
          return true;

         bool res=   findCycle(board,newX,newY,visited,ch,n,m,currX,currY);
          if(res) return true;
    }

    visited[currX][currY]=false;

    return false;

}

bool hasCycle(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    vector<vector<bool>> visited(n,vector<bool>(m,false));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
             if(visited[i][j]==false)
             {
                 char ch=board[i][j];
                bool res=findCycle(board,i,j,visited,ch,n,m,-1,-1);
                if(res) return true;
             }
        }
    }

    return false;
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  
int find_large_piece(vector<vector<int>> &cake,int n,int i,int j,vector<vector<bool>> & visited)
{
    if(i<0 || i>=n ||j>=n || j<0||visited[i][j] || cake[i][j]!=1)
       return 0;
     visited[i][j]=true;
   
    int a=find_large_piece(cake,n,i+1,j,visited);
    int b=find_large_piece(cake,n,i-1,j,visited);
    int c=find_large_piece(cake,n,i,j+1,visited);
    int d=find_large_piece(cake,n,i,j-1,visited);  
    return 1+(a+b+c+d);
}


int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    vector<vector<bool>> visited(n,vector<bool>(n,false));

   int mx=0;
    for(int i=0;i<cake.size();i++)
    {
        for(int j=0;j<cake[i].size();j++)
        {
            if(cake[i][j]==1 && !visited[i][j])
             {
                int count= find_large_piece(cake,n,i,j,visited);
                mx=max(count,mx);
             } 
        }
    }
    return mx;

}

int findLarge(vector<vector<int>> & cake,vector<vector<bool>> visited,int i,int j,int n)
{
    visited[i][j]=true;
   
   int count=0;

    int diffX[4]={-1, 0, 1,0};
    int diffY[4]={0,1,0,-1};


    for(int k=0;k<4;k++)
    {
        int newX=i+diffX[k];
        int newY=i+diffY[k];
    
       if(newX<n && newX>=0 && newY<n && newY>=0)
       {
            if(cake[newX][newY]==1 && !visited[newX][newY])
            {
               count+=  findLarge(cake,visited,newX,newY,n);
            }
       }
    }
    // cout<<count<<" ";
  return count+1;
    
}
int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here

    vector<vector<bool>> visited(n,vector<bool>(n,false));
    int maxPeace=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(cake[i][j]==1 && !visited[i][j])
            {
                int count=findLarge(cake,visited,i,j,n);
                if(count>maxPeace)
                 maxPeace=count;
            }
        }
    }
    return maxPeace;
}
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
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

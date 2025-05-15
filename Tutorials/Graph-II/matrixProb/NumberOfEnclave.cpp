class Solution {
public:
   void traverseDFS(vector<vector<int>>& board, vector<vector<bool>>& visited,int x,int y, int m, int n)
   {
      visited[x][y]=true;
   
      int diffX[4]={-1,0,1,0};
      int diffY[4]={0,1,0,-1};

      for(int i=0;i<4;i++)
      {
         int newX=x+diffX[i];
        int newY=y+diffY[i];

        if(newX>=0 && newX<m && newY>=0 && newY<n )
        {
            if(!visited[newX][newY] && board[newX][newY]==1)
            {
                traverseDFS(board,visited, newX, newY,m,n); 
            }
        }
      }
      
   }
    int numEnclaves(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i=0;i<n;i++)
        {
            if(!visited[0][i] && board[0][i]==1)
             traverseDFS(board,visited,0,i,m,n);

             if(!visited[m-1][i] && board[m-1][i]==1)
                   traverseDFS(board,visited,m-1,i,m,n);
        }

        for(int i=0;i<m;i++)
        {
            if(!visited[i][0] && board[i][0]==1)
             traverseDFS(board,visited,i,0,m,n);

             if(!visited[i][n-1] && board[i][n-1]==1)
                   traverseDFS(board,visited,i,n-1,m,n);
        }
      int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1 && !visited[i][j])
                  count++;
            }
        }
        return count;

    }
    
};

class Solution {
public:
    bool search(vector<vector<char>>& board,int i,int j,int strInd, string word,int m,int n)
    {
        if(strInd==word.length())
          return true;

        if(i>=m || i<0 || j>=n || j<0)
         return false;  

        if(board[i][j]!=word[strInd] || board[i][j]=='!')
         return false; 

         char ch=board[i][j];
         board[i][j]='!';

       bool a= search(board,i+1,j,strInd+1,word,m,n);
       bool b= search(board,i,j+1,strInd+1,word,m,n);
       bool c= search(board,i,j-1,strInd+1,word,m,n);
       bool d= search(board,i-1,j,strInd+1,word,m,n);

       board[i][j]=ch;
       return a|| b||c|| d;
    }
    bool exist(vector<vector<char>>& board, string word) {
       int m=board.size();
       int n=board[0].size();
       for(int i=0;i<m;i++)
       {
         for(int j=0;j<n;j++)
         {
            if(board[i][j]==word[0])
            {
                bool res=search(board,i,j,0,word,m,n);
                if(res)return true;
            }  
         }
       }
       return false; 
    }
};
**************************************************************************************************************
class Solution {
public:
    bool search(vector<vector<char>>& board,int currX,int currY,int strInd, string word,int m,int n,vector<vector<bool>>& visited)
    {
        if(strInd==word.length())
          return true;
       
       visited[currX][currY]=true;

           int diffx[4] = {-1, 1, 0, 0};
        int diffy[4] = {0, 0, -1, 1};

        for(int i=0;i<4;i++)
        {
            int newX=currX+diffx[i];
            int newY=currY+diffy[i];

            if(newX>=0 && newX<m && newY>=0 && newY<n)
            {
                if(board[newX][newY]==word[strInd] && !visited[newX][newY])
                {
                    int res=search(board,newX,newY,strInd+1,word,m,n,visited);
                    if(res)return true;
                }
            }
        }
        visited[currX][currY]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
       int m=board.size();
       int n=board[0].size();
       for(int i=0;i<m;i++)
       {
         for(int j=0;j<n;j++)
         {
            if(board[i][j]==word[0])
            {
                vector<vector<bool>> visited(m, vector<bool>(n, false));  
                bool res=search(board,i,j,1,word,m,n,visited);
                if(res)return true;
            }  
         }
       }
       return false; 
    }
};

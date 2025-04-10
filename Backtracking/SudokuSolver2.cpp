class Solution {
public:
   bool findEmptyPos(vector<vector<char>> & board,int& row,int& col)
   {
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            if(board[i][j]=='.')
            {
               row=i;
               col=j;
               return true;
            }

        }
    }
    return false;
   }
   bool isSafeRow(const vector<vector<char>> &board, int row,int col,char num)
   {
      for(int j=0;j<board[row].size();j++)
      {
         if(board[row][j]==num)
           return false;
      }
      return true;
   }
   bool isSafeCol(const vector<vector<char>> &board, int row,int col,char num)
   {      
      for(int i=0;i<board.size();i++)
      {
          if(board[i][col]==num)
            return false;
      }
      return true;
   }
   bool isSafeGrid(const vector<vector<char>>& board, int row,int col,char num)
   {
    
   int rowFact=row-(row%3);
   int colFact=col-(col%3);

   for(int i=0;i<3;i++)
   {
    for(int j=0;j<3;j++)
      if(board[i+rowFact][j+colFact]==num)
        return false;
   }
   return true;
   }
   bool isSafe(const vector<vector<char>>& board, int row,int col,char num)
   {
      if(isSafeRow(board,row,col,num) && isSafeCol(board,row,col,num) && isSafeGrid(board,row,col,num))
        return true;

      return false;  
     
   }
    bool solvesuduku(vector<vector<char>> & board)
    {
        int row ,col;
        if(!findEmptyPos(board,row,col))
            return true;

         for(int i=1;i<=9;i++)
         {
            char ch = i + '0';
            if(isSafe(board,row,col,ch))
            {
                board[row][col]=ch;
                if(solvesuduku(board))
                  return true;
                board[row][col]='.';  
            }
         }
         return false;   
    }
    void solveSudoku(vector<vector<char>>& board) {
         solvesuduku(board);
         
    }
};

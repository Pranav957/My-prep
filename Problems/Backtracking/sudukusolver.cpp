#include<bits/stdc++.h>
using namespace std;
#define N 9
bool is_safeingrid(int board[N][N],int row,int col,int num)
{
    int row_fact=row-(row%3);
    int col_fact=col-(col%3);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i+row_fact][j+col_fact]==num)
              return false;
        }
    }
    return true;
}
bool is_safe_row(int board[N][N],int row,int num)
{
    for(int i=0;i<N;i++)
    {
        if(board[row][i]==num)
         return false;
    }
    return true;
}
bool is_safeincol(int board[N][N], int col, int num) {
  for (int i = 0; i < N; i++) {
    if (board[i][col] == num)
      return false;
  }
  return true;
}
bool is_safe(int board[N][N],int row,int col,int num)
{
    if(is_safe_row(board,row,num)&& is_safeincol(board,col,num)&& is_safeingrid(board,row,col,num))
      {
            return true;
      }
      return false;
}
bool find_empty(int board[N][N],int& row,int& col)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(board[i][j]==0)
             {
                 row=i;
                 col=j;
                 return true;
             }
        }
    }
    return false;
}
bool Solve_sudoku(int board[N][N])
{
    int row,col;
    if(!find_empty(board,row,col))
       return true;
     for(int i=1;i<=N;i++)  
     {
         if(is_safe(board,row,col,i))
         {
             board[row][col]=i;
             if(Solve_sudoku(board))
               return true;
             board[row][col]=0;
            // cout << row << " " << col << "\n";
         }
     }
     //cout<<row<<" "<<col<<"\n";
     return false; 
}
int main(){
    
    // write your code here
    int board[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
          cin >> board[i][j];
    }
    if(Solve_sudoku(board))
    {
      cout << "true" << endl;
    }
    else
      cout<<"false"<<endl;  
    

    return 0;
}
int arr[11][11];
vector<vector<int>> ans;

bool checkpossibility(int n, int row, int col)
{
    for(int i=row-1;i>=0;i--)
    {
        if(arr[i][col]==1)
         return false;
    }
  int i,j;
    for(  i=row-1,  j=col-1; i>=0 && j>=0; i--,j--)
    {
        if(arr[i][j]==1)
          return false;
    }

     for( i=row-1,  j=col+1; i>=0 && j<n;i--,j++)
    {
        if(arr[i][j]==1)
          return false;
    }
    return true;
}
void nQueensHelper(int n, int row)
{
   if(row==n)
   {
      vector<int> v;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<n;j++)
          {
             v.push_back(arr[i][j]);
          }
      }
       ans.push_back(v);
   }

   for(int i=0;i<n;i++)
   {
     if(checkpossibility(n,row,i) )
     {
         arr[row][i]=1;
         nQueensHelper( n,row+1);
         arr[row][i]=0;
     }
   }
}
vector<vector<int>> nQueens(int n)
{
    // Write your code here.
     nQueensHelper(n,0);
     return ans;
}
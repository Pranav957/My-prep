
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
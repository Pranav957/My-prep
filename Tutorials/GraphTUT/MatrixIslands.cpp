class Solution {
public:
   void travelDFS(vector<vector<char>>& grid, int i,int j,vector<vector<bool>>& visited,int m,int n)
   {
      visited[i][j]=true;

       int diffX[4]={-1, 0, 1,0};
       int diffY[4]={0,1,0,-1};

       for(int k=0;k<4;k++)
       {
        int newX=i+diffX[k];
        int newY=j+diffY[k];

        if(newX<m && newX>=0 && newY<n && newY>=0)
        {
            if(grid[newX][newY]=='1' && !visited[newX][newY])
              travelDFS(grid,newX,newY,visited,m,n);
        }

       }
   }

void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int startX, int startY, int m, int n) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    // 4-directional movement: up, right, down, left
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int newX = x + dx[k];
            int newY = y + dy[k];

            // Check bounds and conditions
            if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                grid[newX][newY] == '1' && !visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
}

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int count=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    travelDFS(grid,i,j,visited,m,n);
                    count++;
                }
            }
        }
        return count;
    }
};

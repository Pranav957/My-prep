class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // vector<vector<bool>> visited(m,vector<bool>(n,false));
        int frsh = 0;
        queue<pair<int,int>> rottenOragnes;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                   rottenOragnes.push({i,j});
                } else if(grid[i][j]==1){
                    frsh++;
                }
            }
        }
        if(frsh == 0) return 0;
        int diffX[4]={-1,0,1,0};
        int diffY[4]={0,1,0,-1};
        
        int count=-1;
        while(!rottenOragnes.empty())
        {
            int size=rottenOragnes.size();
            count++;
            for(int j=0;j<size;j++)
            {
                auto [x,y]=rottenOragnes.front();
            rottenOragnes.pop();

            for(int i=0;i<4;i++)
            {
                int newX=x+diffX[i];
                int newY=y+diffY[i];

                if(newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY]==1)
                {
                    rottenOragnes.push({newX,newY});
                    grid[newX][newY]=2;
                    frsh--;
                }
            }
            }
        }

         if(frsh>0)
          return -1;
        return count;

    }
};

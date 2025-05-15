class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> output(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                 output[i][j]=image[i][j];
            }
        }

          queue<pair<int,int>> q;
          q.push({sr,sc});
          output[sr][sc]=color;

          int diffX[4]={-1,0,1,0};
          int diffY[4]={0,1,0,-1};

          while(!q.empty())
          {
            auto [x,y]=q.front();
            q.pop();

              for(int i=0;i<4;i++)
            {
                int newX=x+diffX[i];
                int newY=y+diffY[i];

                if(newX>=0 && newX<m && newY>=0 && newY<n )
                {
                    if(image[newX][newY]==image[x][y] && output[newX][newY]!=color)
                    {
                        q.push({newX,newY});
                        output[newX][newY]=color;
                    }
                }
            }
          }

         return output;

    }
};

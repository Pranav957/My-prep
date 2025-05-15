class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> output(m,vector<int>(n,INT_MAX));
        

       for(int i=0;i<mat.size();i++)
       {
         for(int j=0;j<mat[i].size();j++)
         {
             if(mat[i][j]==0)
             {
                output[i][j]=0;
                q.push({i,j});
             }
         }
       }

       int diffX[4]={-1,0,1 ,0};
       int diffY[4]={0,1,0,-1};
       while(!q.empty())
       {
          auto [x,y]=q.front();
          q.pop();

          for(int i=0;i<4;i++)
          {
            int newX=x+diffX[i];
            int newY=y+diffY[i];

            if(newX<m && newX>=0 && newY<n && newY>=0)
            {
                if(output[newX][newY]>output[x][y]+1)
                {
                    output[newX][newY]=output[x][y]+1;
                       q.push({newX,newY});
                }
                
            }
          }
       }
       return output;
    }
// vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//     int m = mat.size(), n = mat[0].size();
//     vector<vector<int>> output(m, vector<int>(n, INT_MAX));
//     queue<pair<int, int>> q;

//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if (mat[i][j] == 0) {
//                 output[i][j] = 0;
//                 q.push({i, j});
//             }
//         }
//     }

//     int dx[] = {-1, 0, 1, 0};
//     int dy[] = {0, 1, 0, -1};

//     while (!q.empty()) {
//         auto [x, y] = q.front(); q.pop();
//         for (int i = 0; i < 4; i++) {
//             int newX = x + dx[i];
//             int newY = y + dy[i];
//             if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
//                 if (output[newX][newY] > output[x][y] + 1) {
//                     output[newX][newY] = output[x][y] + 1;
//                     q.push({newX, newY});
//                 }
//             }
//         }
//     }

//     return output;
// }

};

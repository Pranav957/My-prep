#include <bits/stdc++.h> 
// most of Grid problems are devided as 
//fixed start to fixed end
// fixed start to variable end
// variable start to variable end

// check if i j is going out of scope
// decide smallest base case which is valid other wise can take smaller than that  but iterative think of both perspective
// if two rows are currently active obtimize space using two  vectors And if two variable/indexes are active then use two variable sfor obtimizatiom

// space Obtimization for
// 1D-> two variables
//2D-> 1D dp/ vector;
//3D-> 2D dp/vector;

int maximumChocolates(vector<vector<int>> &grid,int i,int j1,int j2,int ro,int co, vector<vector<vector<int>>>& dp)
{
    if(j1<0 || j1>=co || j2<0 || j2>=co)  // it may happen that when value of i is n-1/ro-1 j go outof scope so defoine before base case
      return 0;

    if(i==ro-1)
    {
      if(j1==j2)
        return grid[i][j1];
      return grid[i][j1]+grid[i][j2];  
    }
     
     if(dp[i][j1][j2]!=-1)
       return dp[i][j1][j2];

      // int a=maximumChocolates(grid,i+1,j1-1,j2-1,ro,co);  //alice and bob traveling grid together as for each move of alice bob can travel 3 diffrent places
      // int b=maximumChocolates(grid,i+1,j1,j2-1,ro,co);
      // int c=maximumChocolates(grid,i+1,j1+1,j2-1,ro,co);

      //  int d=maximumChocolates(grid,i+1,j1-1,j2,ro,co);
      // int e=maximumChocolates(grid,i+1,j1,j2,ro,co);
      // int f=maximumChocolates(grid,i+1,j1+1,j2,ro,co);

      //  int g=maximumChocolates(grid,i+1,j1-1,j2+1,ro,co);
      // int h=maximumChocolates(grid,i+1,j1,j2+1,ro,co);
      // int k=maximumChocolates(grid,i+1,j1+1,j2+1,ro,co);

      int mx=INT_MIN;
      for(int dj1 = -1; dj1 <= 1; dj1++) {
    for(int dj2 = -1; dj2 <= 1; dj2++) {
        mx=max(maximumChocolates(grid,i+1,j1+dj1,j2+dj2,ro,co,dp),mx);
    }
}

      int chocolates = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
int ans = chocolates+ mx; //+ max({a,b,c,d,e,f,g,h,k});

      return dp[i][j1][j2]=ans;


}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {

  //  vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
  //   return maximumChocolates(grid,0,0,c-1,r,c,dp);
 int ro=r,co=c;
 vector<vector<vector<int>>> dp(ro, vector<vector<int>>(co, vector<int>(co, 0)));
// base case
for(int j1 = 0; j1 < co; j1++) {              // when i reaches n-1/ro-1there qare 9 different combinations of j1 and j2 are possible
    for(int j2 = 0; j2 < co; j2++) {
        if(j1 == j2)
            dp[ro-1][j1][j2] = grid[ro-1][j1];
        else
            dp[ro-1][j1][j2] = grid[ro-1][j1] + grid[ro-1][j2];
    }
}

// bottom-up calculation
for(int i = ro-2; i >= 0; i--) {        // express every state in for loop
    for(int j1 = 0; j1 < co; j1++) {
        for(int j2 = 0; j2 < co; j2++) {

            int maxi = -1e8;

            for(int dj1 = -1; dj1 <= 1; dj1++) {
                for(int dj2 = -1; dj2 <= 1; dj2++) {
                    int newJ1 = j1 + dj1;
                    int newJ2 = j2 + dj2;

                    if(newJ1 >= 0 && newJ1 < co && newJ2 >= 0 && newJ2 < co) {       
                        int value = dp[i+1][newJ1][newJ2];
                        int curr = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                        value += curr;
                        maxi = max(maxi, value);
                    }
                }
            }
            dp[i][j1][j2] = maxi;
        }
    }
}
 return dp[0][0][co-1]; //  j1 started at 0 cell and j2 started from co-1 cell  of oth row
}

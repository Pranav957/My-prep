class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle,int idx, int ele,vector<vector<int>>& dp) {
        if(idx==triangle.size())
         return 0;

         if(dp[idx][ele]!=-1)
           return dp[idx][ele];

       int a= minimumTotal(triangle,idx+1,ele,dp);
       int b= minimumTotal(triangle,idx+1,ele+1,dp );

       return dp[idx][ele]=triangle[idx][ele]+min(a,b);

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return minimumTotal(triangle,0,0,dp);
        vector<vector<int>> dp(n,vector<int>(n));

        for(int j=0;j<triangle[n-1].size();j++)
           dp[n-1][j]=triangle[n-1][j];

         for(int i=n-2;i>=0;i--)
         {
            for(int j=i;j>=0;j--)
            {
                int b=INT_MAX;
                int a=dp[i+1][j];
                 b=dp[i+1][j+1];

                 dp[i][j]=triangle[i][j]+min(a,b);
            }
         }

         return dp[0][0];  

    }
};

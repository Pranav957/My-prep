class Solution {
  public:
  //     int maximumPoints(vector<vector<int>>& arr,int idx,int ele,vector<vector<int>>& dp) {
//         // Code here
//         if(idx==arr.size())
//           return 0;
          
//           if(dp[idx][ele]!=-1)
//             return dp[idx][ele];
          
//         int a=INT_MIN,b=INT_MIN,c=INT_MIN;  
//          if(ele!=0)
//             a=arr[idx][0]+ maximumPoints(arr,idx+1,0,dp);
//          if(ele!=1)  
//              b=arr[idx][1]+maximumPoints(arr,idx+1,1,dp);
//          if(ele!=2)        
//              c=arr[idx][2]+maximumPoints(arr,idx+1,2,dp);
    
//          return dp[idx][ele]= max({a,b,c});         
        
//     }
  int maximumPoints(vector<vector<int>>& arr,int n,int ele,vector<vector<int>>& dp) {
        // Code here
        if(n==0)
          return 0;
          
          if(dp[n][ele]!=-1)
            return dp[n][ele];
          
        int a=INT_MIN,b=INT_MIN,c=INT_MIN;  
         if(ele!=0)
            a=arr[n-1][0]+ maximumPoints(arr,n-1,0,dp);
         if(ele!=1)  
             b=arr[n-1][1]+maximumPoints(arr,n-1,1,dp);
         if(ele!=2)        
             c=arr[n-1][2]+maximumPoints(arr,n-1,2,dp);
    
         return  dp[n][ele]=max({a,b,c});         
        
    }
   
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(4,-1));
         return maximumPoints(arr,n,3,dp);
         
    // vector<vector<int>> dp(n, vector<int>(3, 0));

    // Base case: day 0
    for (int j = 0; j < 3; j++) {
        dp[0][j] = arr[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int maxi = 0;
            for (int k = 0; k < 3; k++) {
                if (k != j) {
                    maxi = max(maxi, dp[i-1][k]);
                }
            }
            dp[i][j] = arr[i][j] + maxi;
        }
    }

    return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}
};
// **************************************************************************************************************************************************************************************8
 int maximumPoints(vector<vector<int>>& arr){
        
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(3));
        
        
        // return maximumPoints(arr,n,3,dp);
        
        for(int j=0;j<3;j++)
          dp[0][j] = arr[0][j];
          
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                int a=INT_MIN,b=INT_MIN,c=INT_MIN;  
                if(j!=0)
                  a=arr[i-1][j]+dp[i-1][j];
                 if(j!=1)  
                  b=arr[i-1][j]+dp[i-1][j];
                 if(j!=2)
                    c=arr[i-1][j]+dp[i-1][j];
              dp[i][j]=max({a,b,c});        
            }
        }
        return   max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
        
    }

class Solution {
  public:
     int minCost(vector<int>& height, int n, vector<int>& dp) {
        if (n <= 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int a = abs(height[n ] - height[n - 1]) + minCost(height, n - 1, dp);
        int b = INT_MAX;
          if(n>=2)
            b = abs(height[n ] - height[n - 2]) + minCost(height, n - 2, dp);

        return dp[n] = min(a, b);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n + 1, -1);
        // return minCost(height, n-1, dp);
        dp[0]=0;
        
        for(int i=1;i<n;i++)
        {
            int a=abs(height[i] - height[i - 1])+dp[i-1];
            int b=INT_MAX;
            if(i>=2)
             b=abs(height[i] - height[i - 2])+dp[i-2];
            
            dp[i]=min(a,b); 
        }
        return dp[n-1];
    }
};

************************8space obtimization ****************************************************
int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n + 1, -1);
        // return minCost(height, n-1, dp);
         int prev=0;
         int prev2=0;
         
        
        for(int i=1;i<n;i++)
        {
            int a=abs(height[i] - height[i - 1])+prev;
            int b=INT_MAX;
            if(i>=2)
             b=abs(height[i] - height[i - 2])+prev2;
            
           int curr=min(a,b);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
***************************************************************************************
//  with k solution
// class Solution {
// public:
//     int frogJump(vector<int>& heights, int k,int n) {
//         if(n<=0)
//          return 0;
   
//     int mn=INT_MAX;
//      for(int i=1;i<k;i++)
//       if(n-i>=1)
//       {
//          int a= frogJump(heights,k,n-i)+abs(heights[n-1]-heights[n-i-1]);
//          mn=min(a,mn);
//       }
//       return mn;
//     }
   
//      int frogJump(vector<int>& heights, int k){
//         return frogJump(heights,k,heights.size());
//      }
// };

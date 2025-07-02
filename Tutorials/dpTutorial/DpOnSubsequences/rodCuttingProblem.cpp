
// User function Template for C++

class Solution {
    
  public:
     int cutRod(vector<int>& price,vector<int> length,int n,int rodSize, int** dp)
     {
        //  if(n==0 || rodSize==0 )
        //   return 0;
           
        //   if(dp[n][rodSize]!=-1)
        //      return dp[n][rodSize];
           
        //   if(length[n-1]<=rodSize)
        //   {
        //       int x=price[n-1]+cutRod(price,length,n,rodSize-length[n-1],dp);
        //       int y=cutRod(price,length,n-1,rodSize,dp);
        //       return dp[n][rodSize]=max(x,y);
        //   }
        //  return dp[n][rodSize]= cutRod(price,length,n-1,rodSize,dp);
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0)
                 dp[i][j]=0;
            }
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(length[i-1]<=j)
                {
                   dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]],  // include
               dp[i - 1][j]);
                }
                else
                 dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][rodSize];
     }
    int cutRod(vector<int> &price) {
        int n=price.size();
        int** dp=new int*[n+1];
        
        for(int i=0;i<=n;i++)
        {
            dp[i]=new int[n+1];
            for(int j=0;j<=n;j++)
              dp[i][j]=-1;
        }  
        
        // code here
        vector<int> length(price.size());
        for(int i=0;i<price.size();i++)
          length[i]=i+1;
          
        return cutRod(price,length,price.size(),price.size(),dp);  
    }
};

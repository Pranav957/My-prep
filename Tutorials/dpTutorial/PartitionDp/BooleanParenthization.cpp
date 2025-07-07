// User function Template for C++
class Solution {
  public:
   int countWays(string &s,int i,int j,bool isTrue, vector<vector<vector<int>>>& dp) {
        // code here
        if(i>j) return 0;
        
        if (i == j) {
        if (isTrue) return s[i] == 'T';
        else return s[i] == 'F';
    }
    
    if(dp[i][j][isTrue]!=-1)
      return dp[i][j][isTrue];
        
        int sum=0;
        
        for(int k=i+1;k<j;k++)
        {
            int leftT=countWays(s,i,k-1,true,dp);
            int leftF=countWays(s,i,k-1,false,dp);
            int rightT=countWays(s,k+1,j,true,dp);
            int rightF=countWays(s,k+1,j,false,dp);
            
            if (s[k] == '&') {
            if (isTrue)
                sum += leftT * rightT;
            else
                sum += leftT * rightF + leftF * rightT + leftF * rightF;
        } else if (s[k] == '|') {
            if (isTrue)
                sum += leftT * rightT + leftT * rightF + leftF * rightT;
            else
                sum += leftF * rightF;
        } else if (s[k] == '^') {
            if (isTrue)
                sum += leftT * rightF + leftF * rightT;
            else
                sum += leftT * rightT + leftF * rightF;
        }
              
        }
        return dp[i][j][isTrue]=sum;
        
    }
    int countWays(string &s) {
        // code here
        int n=s.length();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return countWays(s,0,s.length()-1,true,dp);
    }
};
*********************************************************************************************************************************************
int countWays(string &s) {
        // code here
        int n=s.length();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        // return countWays(s,0,s.length()-1,true,dp);
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,0)));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<2;k++)
                {
                    if(i==j)
                    {
                        if(k==1)
                        {
                            dp[i][j][k]=s[i]=='T';
                        }
                        else
                         dp[i][j][k]=s[i]=='F';
                    }
                }
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=n-1;j++)
            {
                for(int d=0;d<2;d++)
                {
                    if(i>=j)continue;
                    int sum=0;
                    for(int k=i+1;k<j;k++)
                    {
                        int leftT = dp[i][k-1][1];
                        int leftF = dp[i][k-1][0];
                        int rightT = dp[k+1][j][1];
                        int rightF = dp[k+1][j][0];
                        
                        if (s[k] == '&') {
                        if (d)
                            sum += leftT * rightT;
                        else
                            sum += leftT * rightF + leftF * rightT + leftF * rightF;
                    } else if (s[k] == '|') {
                        if (d)
                            sum += leftT * rightT + leftT * rightF + leftF * rightT;
                        else
                            sum += leftF * rightF;
                    } else if (s[k] == '^') {
                        if (d)
                            sum += leftT * rightF + leftF * rightT;
                        else
                            sum += leftT * rightT + leftF * rightF;
                    }
                          
                    }
                    
                    dp[i][j][d]=sum;
                }
            }
        }
        return dp[0][n-1][1];
        
    }

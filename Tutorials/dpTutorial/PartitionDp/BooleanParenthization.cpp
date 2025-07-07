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

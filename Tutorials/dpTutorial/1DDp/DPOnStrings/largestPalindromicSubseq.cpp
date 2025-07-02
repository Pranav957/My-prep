class Solution {
public:
int longestCommonSubsequence(string text1, string text2) {
         int m=text1.length();
        int n=text2.length();

        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);

          for(int i=1;i<m+1;i++)
          {
            for(int j=1;j<n+1;j++)
               if(text1[i-1]==text2[j-1])
                 curr[j]=1+prev[j-1];
               else
               {
                curr[j]=max(curr[j-1],prev[j]);
               }
               prev=curr;  
          }

          return prev[n];
    }
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s.begin(),s.end());
        return longestCommonSubsequence(s,s2);
    }
};

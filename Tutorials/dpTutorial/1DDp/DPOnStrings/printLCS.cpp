 string longestCommonSubsequence(string text1, string text2) {
         int m=text1.length();
        int n=text2.length();

        int** dp=new int*[m+1];
        for(int i=0;i<=m;i++)
        {
            dp[i]=new int[n+1];
        }

        for(int i=0;i<m+1;i++)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<n+1;j++)
          dp[0][j]=0;

          for(int i=1;i<m+1;i++)
          {
            for(int j=1;j<n+1;j++)
               if(text1[i-1]==text2[j-1])
                 dp[i][j]=1+dp[i-1][j-1];
               else
               {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
               }  
          }

		  int i=m; int j=n;
		  string s="";
		  while(i>0 && j>0)
		  {
			  if(text1[i-1]==text2[j-1])
               {
				   s.push_back(text1[i-1]);
				   i--;j--;
			   } 
			   else{
				   if(dp[i][j-1]>dp[i-1][j])
				     j--;
				   else
				    i--;	 
			   }
		  }
		  reverse(s.begin(),s.end());
  return s;

}
string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.
   return  longestCommonSubsequence(s1,s2);
}
**********************************************************************************************************************************************************************




class Solution {
    priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> pq;
    set<string> seen;

public:
    void allLcs(const string& s1, const string& s2, string str)
    {
        if (s1.length() == 0 || s2.length() == 0)
        {
            if (seen.count(str)) return;
            seen.insert(str);

            if (pq.empty())
            {
                pq.push({str.length(), str});
            }
            else
            {
                auto x = pq.top();
                int curLen=x.first;
                if (str.length() > curLen)
                {
                    while (!pq.empty()) pq.pop();
                    pq.push({str.length(), str});
                }
                else if (str.length() == curLen)
                {
                    pq.push({str.length(), str});
                }
            }
            return;
        }

        if (s1[0] == s2[0])
             return allLcs(s1.substr(1), s2.substr(1), str + s1[0]);

        allLcs(s1, s2.substr(1), str);
        allLcs(s1.substr(1), s2, str);
    }

    vector<string> allLCS(string &s1, string &s2) {
        vector<string> v;

        allLcs(s1, s2, "");

        while (!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            v.push_back(x.second);
        }

        return v;
    }
};

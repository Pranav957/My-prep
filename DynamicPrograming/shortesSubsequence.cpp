#include<climits>
#include<bits/stdc++.h>  //assume first char of s is part of subsequence and not part of subsequence
 int dp[1001][1001];
 //memset(dp, -1, sizeof(dp));
 
int solve(string& s, string& v,int i,int j) {
    // Write your code here
    if(i>=s.size()) return 1001;
    if(j>=v.length()) return 1;
    
    if(dp[i][j]!=-1)
        return dp[i][j];
    int k=j;
    for(;k<v.size();k++)
    {
      if(s[i]==v[k])
         break;
    }   
    if(k==v.size())
       return 1;

    return dp[i][j]= min(solve(s,v,i+1,j),1+solve(s,v,i+1,k+1));   
     
}
int solve(string& s,string& v)
{
   
   // memset(dp, -1, sizeof(dp))
    int m=s.length();
   int n=v.length();
    for(int i=0;i<m;i++)
 {
   for(int j=0;j<n;j++)
     dp[i][j]=-1;
 }  
    return solve(s,v,0,0);
}
  /*int solve(string s,string v)
  {
     int m=s.length();
   int n=v.length();
     int **dp=new int*[m];
     for(int i=0;i<m;i++)
     {
       dp[i]=new int[n];
     }  

    
  }*/
/*int solve(string s, string v) 
{
  if(s.length()==0)
      return INT_MAX;
  if(v.length()<=0)
     return 1;
     if(s[0]==v[0])
       return solve(s.substr(1),v.substr(1));
   int a=solve(s.substr(1),v);
   char item=s[0];
   int i=0;
   for(i=0;i<v.length();i++)
   {
     if (v[i] == item)
       break;
   }    
   int b=1+solve(s.substr(1),v.substr(i+1)); 
   return min(a,b);

}
int solve(string s, string v) {
  // Write your code here
  
  if (v.length() <= 0)
    return 1;
  if (s.length() == 0)
    return INT_MAX;
  
  char item = s[0];
  int i;
  for (i = 0; i < v.length(); i++) {
    if (v[i] == item)
      break;
  }
  if(i==v.length())
    return 1;
  int a = solve(s.substr(1), v);
  int b = 1 + solve(s.substr(1), v.substr(i + 1));
  // if(a!=0 && b!=0)
  return min(a, b);
  // if(a==0)
   //  return b;
   //else
   // return a;
}*/

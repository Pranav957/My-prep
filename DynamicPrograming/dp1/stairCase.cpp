#include<bits/stdc++.h>
using namespace std;
int countMinSteps(int n)
{
  if(n<=0)
  {
     if(n==0)
       return 1;
     return 0;  
  }

  int a=countMinSteps(n-1);
  int b=countMinSteps(n-2);
  int c=countMinSteps(n-3);
  return (a+b+c);
}
int main()
{
    // take input from the user.
    int T;
    cin>>T;
    while(T--)
    {
      int n;
      cin >> n;
      int ans=countMinSteps(n);
      cout<<ans<<endl;
    }
    return 0;
}
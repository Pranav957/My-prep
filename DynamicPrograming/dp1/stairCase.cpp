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

int bottom-up(int n){
int* arr=new int[n+1];
    arr[0]=1;
    for(int i=1;i<=n;i++)
    {
        int a=arr[i-1],b=0,c=0;
        if(i-2>=0)
         b=arr[i-2];
        if(i-3>=0)
          c=arr[i-3];
          
        arr[i]=a+b+c;  
    }
    return arr[n];
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

#include<bits/stdc++.h>
using namespace std;
int print_substring(int arr[], int N, int K, vector<int> v,int count)
{
    if(N==0)
    {
        int sum=0;
        for(int i=0;i<v.size();i++)
        {
          sum+=v[i];
        }
        if(sum==K)
            count++;
        return count;
    }

  int ans1=print_substring(arr+1,N-1,K,v,count);
  v.push_back(arr[0]);
  int ans2=print_substring(arr+1,N-1,K,v,count);
    return ans1+ans2;
}
int main(){
    
    // write your code here
    int T;
    cin >> T;
    while(T--)
    {
        int N,K,count=0;
        cin >> N >> K;
        int arr[N];
        vector<int> v;
        for(int i=0;i<N;i++)
        {
            cin >> arr[i];
        }
     int ans=   print_substring(arr,N,K,v,count);
     cout<<ans<<endl;
    }
    return 0;
}
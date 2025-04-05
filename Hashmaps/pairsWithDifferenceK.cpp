#include<unordered_map> 
int getPairsWithDifferenceK(int *arr, int n, int k) {
  // Write your code here
  unordered_map<int, int> mp;
  int count = 0;
  /*for(int i=0;i<n;i++)
  {
	  int x=arr[i]+k;
	  int y=arr[i]-k;
	  for(int j=i+1;j<n;j++)
	  {
         if(arr[j]==x || arr[j]==y)
		  count+=1;
	  }
  }*/
  for(int i=0;i<n;i++)
  {
    int x = arr[i] + k;
    int y = arr[i] - k;
	if(mp.find(x)!=mp.end())
	   count+=mp[x];
     else if( mp.find(y) != mp.end())
      count+=mp[y];
	 mp[arr[i]]++;
  }
  return count;
}
/*#include<unordered_map>
#include<bits/stdc++.h>
int getPairsWithDifferenceK(int *arr, int n, int k) {
        // Write your code here
        unordered_map<int,int> mp;
        int count=0;
        sort(arr , arr+n , greater<int>());

  for(int i=0;i<n;i++)
  {
    int x = arr[i] + k;
        if(mp.find(x)!=mp.end())
        {
                count+=mp[x];
        }
        mp[arr[i]]++;
  }
  return count;
        //for(int i=0;i<n;i++)
        {
       ++mp[arr[i]];
        }
        for(int i=0;i<n;i++)
        {
                int x=arr[i]+k;
                if(mp.count(x)>0)
                {
                        count++;
                        mp[x]--;
                }
        }
        //return count;
}*/
#include<map>
#include<bits/stdc++.h>
int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
       mp[arr[i]]++;

    }

    int max=INT_MIN,val=0;
    for(int i=0;i<n;i++)
    {
          if(mp[arr[i]]>max)
            {
            max = mp[arr[i]];
            val=arr[i];
            }
            
    }
    return val;

}
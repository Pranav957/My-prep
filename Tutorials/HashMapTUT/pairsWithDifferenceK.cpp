#include<unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
	unordered_map<int,int> mp;
	int count=0;
	for(int i=0;i<n;i++)
	{
		++mp[arr[i]];
	}
	for(int i=0;i<n;i++)
	{
		count+=mp[arr[i]]*mp[arr[i]+k];
		count+=mp[arr[i]]*mp[arr[i]-k];
		mp[arr[i]]=0;
	}
   return count;
}

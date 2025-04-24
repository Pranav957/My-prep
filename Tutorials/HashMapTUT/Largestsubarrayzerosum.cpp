#include<unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    unordered_map<int,int> mp;
    int sum=0,maxLength=0;
    for(int i=0;i<n;i++)
    {
       sum+=arr[i];
        if (sum == 0) {
      if (i + 1 > maxLength)
        maxLength = i + 1;
    }
        if(mp.count(sum)>0)
        {
            int length=i-mp[sum];
            if(length>maxLength)
               maxLength=length;
        }
        else 
        mp[sum]=i;
    }
    return maxLength;
}

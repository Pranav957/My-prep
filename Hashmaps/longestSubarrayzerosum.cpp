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

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    int max_len=0;
    for(int i=0;i<n;i++)
    {
        int cur_sum=0;
        for(int j=i;j<n;j++)
        {
            cur_sum+=arr[j];
            if (cur_sum == 0)
              max_len = max(max_len, j - i + 1);
        }
       
    }
    return max_len;
}
/*
#include<unordered_map>
//LONGEST CONSEUCATIVE SUBSEQUENCE
int lengthOfLongestSubsetWithZeroSum(int *arr, int n) {
  // Write your code here
  unordered_map<int, int> mp;
  int sum = 0;
  int longestsubarr = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    if (sum == 0) {
      if (i + 1 > longestsubarr)
        longestsubarr = i + 1;
    }
    if (mp.find(sum) != mp.end()) {
      int length = i - mp[sum];
      if (length > longestsubarr)
        longestsubarr = length;
    } else
      mp[sum] = i;
  }
  return longestsubarr;
}*/
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
       int xr=0;
       unordered_map<int,int> mp;
       mp[xr]=1;
       long count=0;
       for(int i=0;i<arr.size();i++)
       {
           xr=xr^arr[i];
           int x=xr^k;
           if(mp.find(x)!=mp.end()) // can be romoved
             count+=mp[x];
           
           mp[xr]++;     
           
       }
       return count;
    }
};

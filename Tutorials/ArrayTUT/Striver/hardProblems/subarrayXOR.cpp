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
**************************************************************************
int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int xorr = 0;
            for (int K = i; K <= j; K++) {
                xorr = xorr ^ a[K];
            }

            if (xorr == k) cnt++;
        }
    }
    return cnt;
}
*************************************************************************
int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {
            xorr = xorr ^ a[j];

            if (xorr == k) cnt++;
        }
    }
    return cnt;
}

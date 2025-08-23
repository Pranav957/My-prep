// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int m=arr.size(),n=arr[0].size();
         int maxi=0, row=-1;
       for(int i=0;i<m;i++)
       {
           int cnt=0;
           for(int j=0;j<n;j++)
           {
              if(arr[i][j]==1)
               cnt++;
           }
          if(cnt>maxi)
          {
              maxi=cnt;
              row=i;
          }
       }
       return row;
        
    }
};
************************************************************************************
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int m=arr.size(),n=arr[0].size();
         int maxi=0, row=-1;
       for(int i=0;i<m;i++)
       {
           int x=lower_bound(arr[i].begin(),arr[i].end(),1)-arr[i].begin();
           int cnt=n-x;
          if(cnt>maxi)
          {
              maxi=cnt;
              row=i;
          }
       }
       return row;
        
    }
};

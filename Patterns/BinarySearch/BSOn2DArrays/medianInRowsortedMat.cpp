class Solution {
    int findSmallerEq(vector<vector<int>>& mat,int x,int m)
    {
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            cnt+=upper_bound(mat[i].begin(),mat[i].end(),x)-mat[i].begin();
        }
        return cnt;
    }
     
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int low=INT_MAX,high=-1;
        int m=mat.size(), n=mat[0].size();
        int req=(m*n)/2;
        for(int i=0;i<m;i++)
        {
            if(mat[i][0]<low)
             low=mat[i][0];
             
             if(mat[i][n-1]>high)
              high=mat[i][n-1];
        }
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            int smallEq=findSmallerEq(mat,mid,m);
            
            if(smallEq<=req)
             low=mid+1;
            else
             high=mid-1;
        }
        return low;
    }
};

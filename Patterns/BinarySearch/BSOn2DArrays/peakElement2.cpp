class Solution {
public:
   int findRow(vector<vector<int>>& mat,int m,int n,int mid )
   {
     int maxi=-1, ind=-1;
      for(int i=0;i<m;i++)
      {
         if(mat[i][mid]> maxi)
         {
            maxi=mat[i][mid];
            ind=i;
         }
      }
      return ind;
   }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        int low=0, high=n-1;

        while(low<=high)
        {
            int mid=(low+high)/2;

            int row= findRow(mat,m,n,mid);
           
            int left=mid-1>=0? mat[row][mid-1]:-1;
            int right=mid+1<n? mat[row][mid+1]:-1;
            if(mat[row][mid]> left && mat[row][mid]>right)
              return {row,mid};
            else if(mat[row][mid]<left )
              high=mid-1;
            else
             low=mid+1;  

        }
        return {-1,-1};
    }
};

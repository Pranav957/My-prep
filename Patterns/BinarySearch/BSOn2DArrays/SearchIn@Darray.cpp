class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int low=0,high=(m*n)-1;

        while(low<=high)
        {
            int mid=(low+high)/2;

            int row=mid/n; int col=mid%n;

            if(matrix[row][col]==target)
              return true;

              if(matrix[row][col]<target)
                low=mid+1;
              else
               high=mid-1;   
        }
        return false;
    }
};
*****************************************************************************************************************************
class Solution {
    int binarySearch(vector<int>& input, int element,int i,int j)  
{
    while(i<=j)
    {
      int mid=(i+j)/2;
        if(element==input[mid])
         return mid;
         if(element<input[mid])
          {
            j=mid-1;
          }  
          else
           i=mid+1;
    }
    return -1;
}
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            if(target>= matrix[i][0] && target<=matrix[i][n-1])
              return binarySearch(matrix[i],target,0,n-1)!=-1;
        }
        return false;
    }
};

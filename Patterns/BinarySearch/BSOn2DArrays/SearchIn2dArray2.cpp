class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) { //O(m+n)
        int m=matrix.size(),n=matrix[0].size();
       int row=0,col=n-1;
        while(row<m && col>=0)
        {
            if(matrix[row][col]==target)
             return true;
            else if(matrix[row][col]<target)
             row++;
            else
             col--;   
        }
        return false;
    }
};
*******************************************************************************
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
              if(binarySearch(matrix[i],target,0,n-1)!=-1)
               return true;
        }
        return false;
    }
};

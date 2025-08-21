class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int low=1, high=m;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int s=1;
            
            for(int i=0;i<n;i++)
              s=s*mid;
              
              if(s==m)
               return mid;
             
             if(s<m)
             {
                 low=mid+1;
             }  
             else
              high=mid-1;
        }
        return ans;
    }
};

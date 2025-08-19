class Solution {
  public:
     int lowerBound(vector<int>& arr, int target,int low,int high,int n)
     {
         int ans=n;
         
         while(low<=high)
         {
             int mid=(low+high)/2;
             
             if(arr[mid]>=target)
             {
                 ans=mid;
                 high=mid-1;
             }
             else
              low=mid+1;
         }
         return ans;
     }
    int lowerBound(vector<int>& arr, int target) {
        // code here
        // return lowerBound(arr,target,0,arr.size()-1,arr.size());
       int ind=lower_bound(arr.begin(),arr.end(),target)-arr.begin();
       return ind;
    }
};

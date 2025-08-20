class Solution {
  public:
    int findFloor(vector<int>& arr, int target,int low,int high,int n)
     {
         int ans=-1;
         
         while(low<=high)
         {
             int mid=(low+high)/2;
             
             if(arr[mid]<=target)
             {
                 ans=mid;
                 low=mid+1;
             }
             else
              high=mid-1;
         }
         return ans;
     }
    int findFloor(vector<int>& arr, int x) {
        // code here
        return findFloor(arr,x,0,arr.size()-1,arr.size());
    }
};
******************************************************************************************
// User function Template for C++
class Solution {
  public:
   int lowerBound(vector<int>& arr, int target,int low,int high,int n)
     {
         int ans=-1;
         
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
    int findCeil(vector<int>& arr, int x) {
        // code here
        return lowerBound(arr,x,0,arr.size()-1,arr.size());
    }
};

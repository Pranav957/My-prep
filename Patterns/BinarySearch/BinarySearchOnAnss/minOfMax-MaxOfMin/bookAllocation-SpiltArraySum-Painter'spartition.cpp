class Solution {
  public:
    int findAloocation(vector<int>& arr, int pages)
    {
        int stu, pagesAll=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(pagesAll+arr[i]<=pages)
            {
                pagesAll+=arr[i];
            }
            else{
                stu++;
                pagesAll=arr[i];
            }
        }
        return stu;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        
        for(int pages=low;pages<=high;pages++)
        {
             int cntSt=findAloocation(arr,pages);
             if(cntSt==k)return pages;
        }
    }
};
******************************************************************************************************************
class Solution {
  public:
    int findAloocation(vector<int>& arr, int pages)
    {
        int stu=1, pagesAll=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(pagesAll+arr[i]<=pages)
            {
                pagesAll+=arr[i];
            }
            else{
                stu++;
                pagesAll=arr[i];
            }
        }
        return stu;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if (arr.size() < k) return -1;
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        int ans=-1;
       while(low<=high)
        {
            int mid=(low+high)/2;
            
             int cntSt=findAloocation(arr,mid);
             if(cntSt<=k)
             {
                high=mid-1; 
                ans=mid;
             }
             else
              low=mid+1;
        }
        return ans; //return low
    }
};
************************************************SpiltArraySum*******************************
  int splitArray(vector<int>& nums, int k) {
        return findPages(nums,k);
    }

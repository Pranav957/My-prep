// BS on answers (we know the range of answers) (min/max possible int)
class Solution {  // max Integer which on square <=n
  public:
    int floorSqrt(int n) {
        // code here
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            if(i*i<=n)
             ans=i;
            else
             break;
        }
        return ans;
    }
};
*******************************************************************************
class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int low=1,high=n;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int square=mid*mid;
            if(square<=n)
             low=mid+1;
            else
             high=mid-1;
        }
        return high;
    }
};
*****************************************************************************************
class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int low=1,high=n;
        int ans=1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int square=mid*mid;
            if(square<=n)
            {
                low=mid+1;
                ans=mid;
            } 
            else
             high=mid-1;
        }
        return ans;
    }
};

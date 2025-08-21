class Solution {
public:
   long long getTime(vector<int>& piles, int k) {
        long long cnt = 0;
        for (int x : piles)
            cnt += (x + k - 1LL) / k; // ceil(x/k), use 1LL to force 64-bit
        return cnt;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());

        for(int i=1;i<=maxi;i++)
        {
            long long totalTime=getTime(piles,i);
           if(totalTime<=h)
            return i;
        }
        return -1;
    }
};
***********************************************************************************************************************
class Solution {
public:
   long long getTime(vector<int>& piles, int k) {
        long long cnt = 0;
        for (int x : piles)
            cnt += (x + k - 1LL) / k; // ceil(x/k), use 1LL to force 64-bit
        return cnt;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());

        int low=1,high=maxi,ans=1;

        while(low<=high)
        {
            int mid=(low+high)/2;
            long long totalTime=getTime(piles,mid);
             if(totalTime<=h)
             {
                high=mid-1;
                ans=mid;
             } 
             else
              low=mid+1; 
              
        }
        return ans;
    }
};
******************************************************************************************************************************
int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());

        int low=1,high=maxi;

        while(low<=high)
        {
            int mid=(low+high)/2;
            long long totalTime=getTime(piles,mid);
             if(totalTime<=h)
             {
                high=mid-1;
             } 
             else
              low=mid+1; 
              
        }
        return low;
    }

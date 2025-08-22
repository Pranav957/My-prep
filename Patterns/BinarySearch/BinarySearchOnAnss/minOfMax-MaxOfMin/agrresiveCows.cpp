class Solution {
  public:
    bool isPossible(vector<int>& stalls,int k,int dist)
    {
        int cntCows=1,last=stalls[0];
        
        for(int i=1;i<stalls.size();i++)
        {
            if(stalls[i]-last>=dist)
            {
                last=stalls[i];
                cntCows++;
            }
        }
        
        if(cntCows>=k) return true;
        return false;
        
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int maxi=*max_element(stalls.begin(),stalls.end());
        int mini=*min_element(stalls.begin(),stalls.end());
         int mDist=maxi-mini;
         
         sort(stalls.begin(),stalls.end());
         
         for(int i=1;i<=mDist;i++)
         {
             if(isPossible(stalls,k,i))
              continue;
             else
              return i-1;
         }
    }
};
************************************************************************************************************
class Solution {
  public:
    bool isPossible(vector<int>& stalls,int k,int dist)
    {
        int cntCows=1,last=stalls[0];
        
        for(int i=1;i<stalls.size();i++)
        {
            if(stalls[i]-last>=dist)
            {
                last=stalls[i];
                cntCows++;
            }
        }
        
        if(cntCows>=k) return true;
        return false;
        
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int maxi=*max_element(stalls.begin(),stalls.end());
        int mini=*min_element(stalls.begin(),stalls.end());
         int mDist=maxi-mini;
         
         sort(stalls.begin(),stalls.end());
         
         int low=1,high=mDist,ans=-1;
         
         while(low<=high)
         {
             int mid=(low+high)/2;
             if(isPossible(stalls,k,mid))
             {
                 ans=mid;
                 low=mid+1;
             }
             else
              high=mid-1;
         }
         return high;
    }
};

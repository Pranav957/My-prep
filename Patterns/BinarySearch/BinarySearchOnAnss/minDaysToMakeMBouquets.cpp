//[ 7 8 9 10 11 12 13]
//  * * * *  *   ^ ^          *(not possible) ^(possible)
//low              high       high and low ends at opposite polarity hence low will end at lowest possible

class Solution {
public:
  bool isPossible(vector<int>& bloomDay, int m ,int k,int day)
  {
     int cnt=0,numb=0;
           for(int j=0;j<bloomDay.size();j++)
           {
              if(bloomDay[j]>day)
              {
                  numb+=(cnt/k);
                  cnt=0;
              }
              else if(bloomDay[j]<=day)
                 cnt++;
           }
           numb+=cnt/k;
           if(numb>=m)return true;
           return false;
  }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m*k)
         return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isPossible(bloomDay,m,k,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
             low=mid+1;
        }
        return ans;
    }
};
******************************************************************************************
  int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m*k)
         return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());

        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isPossible(bloomDay,m,k,mid))
            {
                high=mid-1;
            }
            else
             low=mid+1;
        }
        return low;
    }
******************************************************************************************************************************************
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<m*k)
         return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());

        for(int i=low;i<=high;i++)
        {
            int cnt=0,numb=0;
           for(int j=0;j<bloomDay.size();j++)
           {
              if(bloomDay[j]>i)
              {
                  numb+=(cnt/k);
                  cnt=0;
              }
              else if(bloomDay[j]<=i)
                 cnt++;
           }
           numb+=cnt/k;
           if(numb>=m)return i;
        }
        return -1;
    }
};
***********************************************************************************************
class Solution {
public:
  bool isPossible(vector<int>& bloomDay, int m ,int k,int day)
  {
     int cnt=0,numb=0;
           for(int j=0;j<bloomDay.size();j++)
           {
              if(bloomDay[j]>day)
              {
                  numb+=(cnt/k);
                  cnt=0;
              }
              else if(bloomDay[j]<=day)
                 cnt++;
           }
           numb+=cnt/k;
           if(numb>=m)return true;
           return false;
  }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<(long long)m*k)
         return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        for(int i=low;i<=high;i++)
        {
            if(isPossible(bloomDay,m,k,i))
              return i;
        }
        return -1;
    }
};

class Solution {
public:
   int getDays(vector<int>& weights,int cap)
   {
    int sum=0,cnt=0;
     for(int i=0;i<weights.size();i++)
     {
        if(sum+weights[i]>cap)
        {
            sum=0;
            cnt++;
        }
       
        sum+=weights[i];
     }
     return cnt+1;
   }
    int shipWithinDays(vector<int>& weights, int days) {
        int high=accumulate(weights.begin(),weights.end(),0);
        int low=*max_element(weights.begin(),weights.end());

        int ans=-1;

        while(low<=high)
        {
            int mid=(low+high)/2;
            if(getDays(weights,mid)<=days)
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
**********************************************************************************************************88888
  class Solution {
public:
   int getDays(vector<int>& weights,int cap)
   {
    int sum=0,cnt=0;
     for(int i=0;i<weights.size();i++)
     {
        if(sum+weights[i]>cap)
        {
            sum=0;
            cnt++;
        }
        if(weights[i]>cap)
          return INT_MAX;
        sum+=weights[i];
     }
     return cnt+1;
   }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=accumulate(weights.begin(),weights.end(),0);

        int low=1,high=maxi,ans=-1;

        while(low<=high)
        {
            int mid=(low+high)/2;
            if(getDays(weights,mid)<=days)
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
********************************************************************************************************************
class Solution {
public:
   int getDays(vector<int>& weights,int cap)
   {
    int sum=0,cnt=0;
     for(int i=0;i<weights.size();i++)
     {
        if(sum+weights[i]>cap)
        {
            sum=0;
            cnt++;
        }
       
        sum+=weights[i];
     }
     return cnt+1;
   }
    int shipWithinDays(vector<int>& weights, int days) {
        int high=accumulate(weights.begin(),weights.end(),0);
        int low=*max_element(weights.begin(),weights.end());


        while(low<=high)
        {
            int mid=(low+high)/2;
            if(getDays(weights,mid)<=days)
            {
                high=mid-1;
            }
            else
              low=mid+1;
        }
        return low;
    }
};
**********************************************************************************************
class Solution {
public:
   int getDays(vector<int>& weights,int cap)
   {
    int sum=0,cnt=0;
     for(int i=0;i<weights.size();i++)
     {
        if(sum+weights[i]>cap)
        {
            sum=0;
            cnt++;
        }
       
        sum+=weights[i];
     }
     return cnt+1;
   }
    int shipWithinDays(vector<int>& weights, int days) {
        int high=accumulate(weights.begin(),weights.end(),0);
        int low=*max_element(weights.begin(),weights.end());


       for(int i=low;i<=high;i++)
        {
            
            if(getDays(weights,i)<=days)
            {
               return i;
            }
        
        }
        return -1;
    }
};

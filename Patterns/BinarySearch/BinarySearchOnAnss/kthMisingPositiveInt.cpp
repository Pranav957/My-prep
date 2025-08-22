class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cnt=0;
        int maxi=*max_element(arr.begin(),arr.end());
        int j=0;
        for(int i=1;i<=maxi;i++)
        {
           if(i!=arr[j])
           {
             cnt++;
              if(cnt==k)
              return i;
             continue;
            
           }
           j++;
        }
            return maxi+k-cnt;
        
    }
};

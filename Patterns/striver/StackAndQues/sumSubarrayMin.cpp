class Solution {
    int MOD=1e9+7;
public:
    vector<int> getLeftMin(vector<int>& arr,int n)
    {
      stack<int> st;
      vector<int>leftMin(n,-1);
      for(int i=0;i<n;i++)
      {
        while(!st.empty()&& arr[st.top()]>=arr[i])   //= is used to handle edge case where arr=[1,1]  (1,1) avoid considering twice
          st.pop();
        if(st.empty())leftMin[i]=-1;
        else leftMin[i]=st.top();
        st.push(i);  
      }
      return leftMin;
    }
    vector<int> getRightMin(vector<int>& arr,int n)
    {
      stack<int> st;
      vector<int>rightMin(n,n);
      for(int i=n-1;i>=0;i--)
      {
        while(!st.empty()&& arr[st.top()]>arr[i])
          st.pop();
        if(st.empty())rightMin[i]=n;
        else rightMin[i]=st.top();
        st.push(i);  
      }
      return rightMin;
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> leftMin=getLeftMin(arr,arr.size());
        vector<int> rightMin=getRightMin(arr,arr.size());
       int total=0;
        for(int i=0;i<arr.size();i++)
        {
            int left=i-leftMin[i];
            int right=rightMin[i]-i;
            total=(total+left*right*1LL*arr[i])%MOD;
        }
        return total;
    }
};

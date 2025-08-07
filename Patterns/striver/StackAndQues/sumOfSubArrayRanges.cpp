class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            int largest=nums[i],smallest=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
               largest=max(nums[j],largest);
               smallest=min(nums[j],smallest); 
              sum=sum+(largest-smallest);
            }
        }
        return sum;
    }
};
******************************************************************************************************************************************************************
class Solution {
public:
   vector<int> getLeftMin(vector<int>& arr,int n)
    {
      stack<int> st;
      vector<int>leftMin(n,-1);
      for(int i=0;i<n;i++)
      {
        while(!st.empty()&& arr[st.top()]>=arr[i])
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

    vector<int> getLeftMax(vector<int>& arr,int n)
    {
      stack<int> st;
      vector<int>leftMax(n,-1);
      for(int i=0;i<n;i++)
      {
        while(!st.empty()&& arr[st.top()]<=arr[i])
          st.pop();
        if(st.empty())leftMax[i]=-1;
        else leftMax[i]=st.top();
        st.push(i);  
      }
      return leftMax;
    }
    vector<int> getRightMax(vector<int>& arr,int n)
    {
      stack<int> st;
      vector<int>rightMax(n,n);
      for(int i=n-1;i>=0;i--)
      {
        while(!st.empty()&& arr[st.top()]<arr[i])
          st.pop();
        if(st.empty())rightMax[i]=n;
        else rightMax[i]=st.top();
        st.push(i);  
      }
      return rightMax;
    }
    
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> leftMin=getLeftMin(arr,arr.size());
        vector<int> rightMin=getRightMin(arr,arr.size());
       long long total=0;
        for(int i=0;i<arr.size();i++)
        {
            int left=i-leftMin[i];
            int right=rightMin[i]-i;
            total=(total+left*right*1LL*arr[i]);
        }
        return total;
    }
    long long  sumSubarrayMaxs(vector<int>& arr) {
        vector<int> leftMax=getLeftMax(arr,arr.size());
        vector<int> rightMax=getRightMax(arr,arr.size());
       long long  total=0;
        for(int i=0;i<arr.size();i++)
        {
            int left=i-leftMax[i];
            int right=rightMax[i]-i;
            total=(total+left*right*1LL*arr[i]);
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
       return (long long)sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};

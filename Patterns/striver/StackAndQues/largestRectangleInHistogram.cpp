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
        while(!st.empty()&& arr[st.top()]>=arr[i])
          st.pop();
        if(st.empty())rightMin[i]=n;
        else rightMin[i]=st.top();
        st.push(i);  
      }
      return rightMin;
    }

    int largestRectangleArea(vector<int>& heights) {
        int maxi=0,n=heights.size();
        vector<int> leftMin=getLeftMin(heights,n);
        vector<int> rightMin=getRightMin(heights,n);
        
        for(int i=0;i<heights.size();i++)
        {
            int area=heights[i]*(rightMin[i]-leftMin[i]-1);
            maxi=max(maxi,area);
        }
        return maxi;
    }
};

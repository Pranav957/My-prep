class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea=0,n=heights.size();

        for(int i=0;i<heights.size();i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                int idx=st.top();
                st.pop();
                int nextSmall=i;
                int prevSmall=st.empty()? -1:st.top();
                int area=heights[idx]*(nextSmall-prevSmall-1);
                maxArea=max(maxArea,area);
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int nextSmall=n;
            int idx=st.top();st.pop();
            int prevSmall=st.empty()? -1:st.top();
            int area=heights[idx]*(nextSmall-prevSmall-1);
                maxArea=max(maxArea,area);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int maxArea=0;
        vector<vector<int>> v(m,vector<int>(n,0));

        for(int j=0;j<n;j++)
        {
            int sum=0;
            for(int i=0;i<m;i++)
            {
                if(matrix[i][j]=='0')
                  sum=0;
                else
                    sum+=1;
               v[i][j]=sum;   
            }
        }

        for(int i=0;i<m;i++)
        {
            maxArea=max(maxArea,largestRectangleArea(v[i]));
        }
        return maxArea;

    }
};

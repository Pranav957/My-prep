class Solution {
public:
    int getMaxRectanle(vector<int>& histo)
    {
        int maxA=0;
        int n=histo.size();
        stack<int> st;
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || histo[i]<=histo[st.top()]))
            {
                int height=histo[st.top()];
                st.pop();
                int width;
                if(st.empty())width=i;
                else width=i-st.top()-1;
                maxA=max(maxA,(height*width));
            }
            st.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;

        vector<int> height(m,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
              if(matrix[i][j]=='1')
                height[j]++;
               else height[j]=0;

            }
         int area= getMaxRectanle(height);
          maxArea=max(area,maxArea);
        }
       return maxArea; 
    } 
    
};

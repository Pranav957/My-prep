int maxArea(vector<int>& height) {
        int maxArea=0;
        for(int i=0;i<height.size();i++)
        {
            for(int j=i+1;j<height.size();j++)
            {
                 int minHeight=min(height[i],height[j]);
                 int width=j-i;
                 int area=minHeight*width;

                 if(area>maxArea)
                  maxArea=area;

            }
        }
        return maxArea;
    }
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
  int maxArea(vector<int>& height) {
        int maxArea=0;
       int i=0,j=height.size()-1;

       while(i<j)
       {
          int minHeight=min(height[i],height[j]);
          int width=j-i;
          int area=minHeight*width;

          if(area>maxArea)
            maxArea=area;

          if(height[i]<height[j])
            i++;
          else
           j--;    
       }
       return maxArea;
    }

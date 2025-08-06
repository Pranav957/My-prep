class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftMax=0,rightMax=0,total=0;
        int l=0,r=n-1;

        while(l<r)
        {
            if(height[l]<=height[r])
            {
                if(leftMax>height[l])
                  total+=leftMax-height[l];
                else
                 leftMax=height[l];  
                 l++;
            }
            else
            {
                if(rightMax>height[r])
                  total+=rightMax-height[r];
                else
                 rightMax=height[r];  
                 r--;
            }
          
        }
        return total;
    }
};
*********************************************************************************************************
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        prefixMax[0]=height[0];
        for(int i=1;i<n;i++)
         prefixMax[i]=max(prefixMax[i-1],height[i]);
        suffixMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
           suffixMax[i]=max(suffixMax[i+1],height[i]); 
        } 

        int total=0;

        for(int i=0;i<n;i++)
        {
            if(height[i]<prefixMax[i] && height[i]<suffixMax[i])
            {
                total+=min(prefixMax[i],suffixMax[i])-height[i];
            }
        }
        return total;

    }
};
*********************************************************************************************************
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        
        suffixMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
           suffixMax[i]=max(suffixMax[i+1],height[i]); 
        } 

        int total=0; 
        int leftMax=INT_MIN;

        for(int i=0;i<n;i++)
        {
            leftMax=max(height[i],leftMax);
            if(height[i]<leftMax && height[i]<suffixMax[i])
            {
                total+=min(leftMax,suffixMax[i])-height[i];
            }
        }
        return total;

    }
};

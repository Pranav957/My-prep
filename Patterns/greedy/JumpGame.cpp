class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1)
         return true;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
             {
                int x=2;
                int j;
                for( j=i-1;j>=0;j--)
                {
                   if(nums[j]>=x)
                    break;

                    if(i==n-1 && nums[j]>=x-1)
                    break;
                    

                    x++;
                }
                if(j==-1)
                 return false;
             } 
        }
        return true;
    }
};
******************************************************************************************************************************************
bool canJump(vector<int>& nums) {
        int maxInd=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>maxInd)
             return false;

             maxInd=max(maxInd,i+nums[i]);
        }
        return true;
    }

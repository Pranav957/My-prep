    int longestOnes(vector<int>& nums, int k) {
        int longest=0;
        int left=0;
        int zeros=0;
        for(int r=0;r<nums.size();r++)
        {
          if(nums[r]==0)
          {
             zeros++;
          }
          if(zeros<=k)
          {
             longest=max(longest,r-left+1);
          }
          else
            {
                while(nums[left]!=0)
                 left++;
               left++;
               zeros--;  
            }
        }
        return longest;
    }
};
*******************************************************************************************88
    class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int longest=0;
        for(int i=0;i<nums.size();i++)
        {
            int zeros=0;
            for(int j=i;j<nums.size();j++)
            {
                if(nums[j]==0)
                 zeros++;
              if(zeros<=k)
                 longest=max(longest,j-i+1);
              else    
                break;
                
            }
        }
        return longest;
    }
};

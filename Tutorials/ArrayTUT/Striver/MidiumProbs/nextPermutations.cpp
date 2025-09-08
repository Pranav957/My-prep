class Solution {
public:
    void nextPermutation(vector<int>& nums) {  // total permutations are n!
        int ind=-1,n=nums.size();  //2 3 | 5 4 1 0 0
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                ind=i;
                break;
            }
        }
        if(ind==-1)
        {
            reverse(nums.begin(),nums.end());
            return ;
        }
        for(int i=n-1;i>ind;i--)
        {
            if(nums[i]>nums[ind])
             {
                int temp=nums[i];
                nums[i]=nums[ind];
                nums[ind]=temp;
                break;
             }
        }

        reverse(nums.begin()+ind+1,nums.end());


    }
};

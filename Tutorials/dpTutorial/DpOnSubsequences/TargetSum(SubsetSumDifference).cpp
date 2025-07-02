#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countsubset(vector<int>& nums,int target)
    {
        vector<vector<int>> dp(nums.size()+1,vector<int>(target+1));

        for(int i=0;i<=nums.size();i++)
        {
            for(int j=0;j<target+1;j++)
            {
                if(i==0)
                 dp[i][j]=0;
                if(j==0)
                  dp[i][j]=1; 
            }

            for(int i=1;i<=nums.size();i++)
            {
                for(int j=0;j<target+1;j++)
                {
                    if(nums[i-1]<=j)
                    {
                        dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                    }
                    else
                     dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[nums.size()][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

    // If not a valid transformation, return 0
    if ((target + sum) % 2 != 0 || abs(target) > sum)
        return 0;

    int subsetTarget = (target + sum) / 2;
    return countsubset(nums, subsetTarget);
    }
};

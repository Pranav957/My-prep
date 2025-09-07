class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum=nums[0];
        int maxSum=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            currentsum=max(nums[i],nums[i]+currentsum);
            maxSum=max(currentsum, maxSum);
        }
        return maxSum;
    }
};
*************************************************************
long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;
     // int ansSt=-1,ansEd=-1;

    for (int i = 0; i < n; i++) {
        // if(sum==0) start=i;
        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
            // ansSt=start;
            // ansEd=i;
        }

        if (sum < 0) {
            sum = 0;
        }
    }

    //if (maxi < 0) maxi = 0;

    return maxi;
}

*******************************************************
int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}

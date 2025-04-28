class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    int count = 0;
    int sum = 0;

    mp[0] = 1; // VERY IMPORTANT to handle subarrays starting from index 0
    
    for(int i=0; i<nums.size(); i++) {
        sum += nums[i];   // running prefix sum

        if (mp.count(sum - k)) {
            count += mp[sum - k];
        }
        mp[sum]++;
    }

    return count;
}
};

string twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}
*****************************************************if nums is not sorted
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mp; // value -> index
    for (int i = 0; i < nums.size(); i++) {
        int need = target - nums[i];
        if (mp.find(need) != mp.end())
            return {mp[need], i};
        mp[nums[i]] = i;
    }
    return {-1, -1};
}  

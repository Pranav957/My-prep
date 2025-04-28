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
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
     int subarraySum(vector<int>& nums, int k) {
        int count=0;
    for(int i=0;i<nums.size();i++)
    {
        int sum=0;
        for(int j=i;j<nums.size();j++)
         {
            sum+=nums[j];
            if(sum==k)
             count++;

         }
    }
    return count;
}
><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
      int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int> mp;
       int count=0;
       if(nums[0]==k)
        count++;
        mp[nums[0]]++;
       for(int i=1;i<nums.size();i++)
       {
          nums[i]=nums[i-1]+nums[i];

          if(nums[i]==k)
           count++;

          int x=nums[i]-k;
          if(mp.count(x)>0)
            count+=mp[x]; 

            mp[nums[i]]++;
       }

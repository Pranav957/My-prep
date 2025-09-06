class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int n=nums.size();
      vector<vector<int>> ans;
      sort(nums.begin(),nums.end());
      for(int k=0;k<n-2;k++)
      {
        if (k > 0 && nums[k] == nums[k-1]) continue; // skip duplicates
           int i=k+1,j=n-1;
           int target=0-nums[k];
           while(i<j)
           {
              if(nums[i]+nums[j]==target)
              {
                  ans.push_back({nums[k],nums[i],nums[j]});
                  while (i < j && nums[i] == nums[i+1]) i++;
                  while (i < j && nums[j] == nums[j-1]) j--;
                  i++;j--;
              }
              else if(nums[i]+nums[j]<target)
                 i++;
              else
               j--;   
           }
      } 
      return ans; 
    }
};
**********************************************************************************************
vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;

    // check all possible triplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
 vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
**************************************************************************
vector<vector<int>> triplet(int n, vector<int> &arr) {
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            //Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            //Find the element in the set:
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

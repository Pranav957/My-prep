// Leaders In Array
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int> ans;
        int n=arr.size();
        int max=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]>=max)
            {
                ans.push_back(arr[i]);
                max=arr[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

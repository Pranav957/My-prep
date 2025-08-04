class Solution {
  public:
     void subsetSums(vector<int>& arr,int sum,int i,vector<int>& ans){
         if(i==arr.size())
         {
             ans.push_back(sum);
             return;
         }  
         
         subsetSums(arr,sum+arr[i],i+1,ans);
         subsetSums(arr,sum,i+1,ans);
     }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> ans;
        subsetSums(arr,0,0,ans);
        return ans;
    }
};

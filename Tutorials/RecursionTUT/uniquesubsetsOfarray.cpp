 void getUniqueSubsets(vector<int> & arr, vector<vector<int>> &ans, vector<int> temp, int i)
 {
     if(i==arr.size())
      {
          ans.push_back(temp);
          return ;
      }
   int j=i+1;
      while(j<arr.size() && arr[i]==arr[j])
      {
         j++;
      }

      getUniqueSubsets(arr,ans,temp,j);
      temp.push_back(arr[i]);
      getUniqueSubsets(arr,ans,temp,i+1);
 }
vector<vector<int>> getUniqueSubsets(vector<int>& arr) {
    // Write Your Code Here  
    vector<vector<int>> ans;
    vector<int> temp;
    getUniqueSubsets(arr,ans,temp,0);  
    return ans;
}

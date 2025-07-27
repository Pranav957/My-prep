class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
      vector<int> ans(N,0);
        for(int i=0;i<N;i++)
        {
            set<int> st;
            for(int j=0;j<N;j++)
            {
                if(arr[j]<arr[i])
                  st.insert(arr[j]);
            }
            ans[i]=st.size()+1;
        }
        return ans;
    }
};
*****************************************************************************
// User function Template for C++

class Solution {
  public:

    vector<int> replaceWithRank(vector<int> &arr, int N) {
      unordered_map<int,int> mp;
      
      vector<int> arr2=arr;
      sort(arr2.begin(),arr2.end());
      int cnt=1;
      for(int i=0;i<N;i++)
      {
          if(mp[arr2[i]]==0)
          {
              mp[arr2[i]]=cnt;
              cnt++;
          }
      }
      vector<int> ans;
      for(int i=0;i<N;i++)
      {
          ans.push_back(mp[arr[i]]); 
      }
      return ans;
    }
};

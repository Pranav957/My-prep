int findNCR(int n,int r)
  {
     int res=1;
     for(int i=0;i<r;i++)
     {
        res=res*(n-i);
        res=res/i+1;
     }
     return res;
  }
*******************************printNthRow**********************************
  int findNCR(int n)
  {
     int ans;
     cout<< ans;
     for(int i=1;i<n;i++)
     {
        ans=ans*(n-i);
        ans=ans/i;
        cout<<ans<<" ";
     }
  }
**************************************************************************print Triangle***************************
  class Solution {
public:
  vector<int> generateRow(int n)
  {
    long long ans=1;
     vector<int> ansRow;
    ansRow.push_back(ans);

     for(int i=1;i<n;i++)
     {
        ans=ans*(n-i);
        ans=ans/i;
        ansRow.push_back(ans);
     }
     return ansRow ;
  }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++)
        {
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};

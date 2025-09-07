int findNCR(int n,int r)
  {
     int res=1;
     for(int i=0;i<r;i++)  // n!/r!*(n-r)!  
     {
        res=res*(n-i);
        res=res/i+1;
     }
     return res;
  }
*******************************printNthRow**********************************
  int findNCR(int n)    //ans* (row-col)/col
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
****************************************************************************************************
long long findNCR(int n, int r) {
    long long res = 1;
    if (r > n - r) r = n - r;  // use symmetry C(n, r) = C(n, n-r)
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for (int i = 0; i < numRows; i++) {
        vector<int> temp;
        for (int j = 0; j <= i; j++) {
            temp.push_back(findNCR(i, j));
        }
        ans.push_back(temp);
    }
    return ans;
}

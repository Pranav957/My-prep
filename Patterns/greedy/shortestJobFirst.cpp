class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        long long wt=0,total=0;
        sort(bt.begin(),bt.end());
        for(int i=0;i<bt.size()-1;i++)
        {
          wt+= bt[i];    
          total=total+wt;
        }
        return total/bt.size();
    }
};

 bool comparator(vector<int> x,vector<int> y)
  {
      return x[0]<y[0];
  }
class Solution {
public:
 
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1)
          return intervals;

          sort(intervals.begin(),intervals.end(),comparator);

          vector<vector<int>> res;

          res.push_back(intervals[0]);
          int j=0;

          for(int i=1;i<intervals.size();i++)
          {
            if(intervals[i][0]<=res[j][1])
            {
                res[j][1]=max(intervals[i][1],res[j][1]);
            }
            else
            {
                vector<int> v={intervals[i][0],intervals[i][1]};
                 res.push_back(v);
                 j++;
            }
          }
          return res;
    }
};

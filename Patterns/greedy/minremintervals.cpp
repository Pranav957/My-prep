class Solution {
public:
  static bool comp( vector<int>& x,vector<int>& y)
  {
    return x[1]<y[1];
  }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        
        int lastEndTime=intervals[0][1];
        int cnt=1;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>=lastEndTime)
            {
                cnt++;
                lastEndTime=intervals[i][1];
            }
            
        }

        return intervals.size()-cnt;
        
    }
};

public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool comp(pair<int,int>x,pair<int,int>y)
    {
        return x.second<y.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        
        vector<pair<int,int>> v;
        for(int i=0;i<end.size();i++)
        {
            v.push_back({start[i],end[i]});
        }
        
        sort(v.begin(),v.end(),comp);
        
        int freeTime=-1;
        int count=0;
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first>freeTime)
            {
                 count++;
                 freeTime=v[i].second;
            } 
        }
        
        return count;
        
    }

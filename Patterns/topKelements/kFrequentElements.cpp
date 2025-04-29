vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int> mp;
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
       for(int i=0;i<nums.size();i++)
       {
          mp[nums[i]]++;
        }

        for(auto& [num,count]: mp)
        {
            pq.push({count,num});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }

        vector<int> v;
        while(!pq.empty())
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;

    }

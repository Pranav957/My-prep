vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> v(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++)
        {
            while(!s.empty() && temperatures[i]>temperatures[s.top()])
            {
                int index=s.top();
                s.pop();
                v[index]=i-index;
            }
            s.push(i);
        }
        return v;
    }

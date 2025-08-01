class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        priority_queue< pair<int,pair<int,int>>> pq;
        set<pair<int,int>> vist;
        
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        
        pq.push({a[0]+b[0],{0,0}});
        vist.insert({0,0});
        vector<int> ans;
       
        while(ans.size()<k)
        {
            auto top=pq.top();
            pq.pop();
            int sum=top.first;
            int i=top.second.first;
            int j=top.second.second;
            
            ans.push_back(sum);
            
            
            if(i+1< a.size() && vist.find({i+1,j})==vist.end())
            {
                pq.push({a[i+1]+b[j],{i+1,j}});
                vist.insert({i+1,j});
            }
            
            if(j+1< b.size() && vist.find({i,j+1})==vist.end())
            {
                pq.push({a[i]+b[j+1],{i,j+1}});
                vist.insert({i,j+1});
            }
            
        }
        return ans;
    }
       
};
******************************************************************************************************************************************************************
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<b.size();j++)
            {
                pq.push(a[i]+b[j]);
                if(pq.size()>k)
                 pq.pop();
            }
        }
        
        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }  
        sort(ans.begin(),ans.end(),greater<int>());
        return ans;
    }
};

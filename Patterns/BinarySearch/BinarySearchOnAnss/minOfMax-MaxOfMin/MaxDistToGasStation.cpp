class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        vector<int> howMany(n-1,0);
        for(int gasStations=1;gasStations<=k;gasStations++)
        {
            long double maxValue=0; int maxIndex=-1;
            for(int i=0;i<n-1;i++)
            {
                long double diff=stations[i+1]-stations[i];
                
                long double secLength = diff / (howMany[i] + 1);
                
                if(secLength>maxValue)
                {
                    maxValue=secLength;
                    maxIndex=i;
                }
            }
            howMany[maxIndex]++;
        }
        long double maxAns=-1;
        for(int i=0;i<n-1;i++)
        {
            long double diff=stations[i+1]-stations[i];
          long double secLength = diff / (howMany[i] + 1);
           maxAns=max(maxAns,secLength);
        }
        return maxAns;
    }
};
*****************************************************************************************************************
class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        vector<int> howMany(n-1,0);
        priority_queue<pair<long double,int>> pq;
        for(int i=0;i<n-1;i++)
        {
           pq.push({arr[i+1]-arr[i],i});  
        }
        for(int gasStations=1;gasStations<=k;gasStations++)
        {
           auto tp=pq.top();po.pop();
           int secIndex=tp.second;
           howMany[secIndex]++;
           long double initDiff=stations[secIndex+1]-stations[secIndex];
           long double newSecLen=initDiff/(long double)(howMany[secInex]+1);
           pq.push({newSecLen, secIndex});
        }
        return pq.top().first;
    }
};

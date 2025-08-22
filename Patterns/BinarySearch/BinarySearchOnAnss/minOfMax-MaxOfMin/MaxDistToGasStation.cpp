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

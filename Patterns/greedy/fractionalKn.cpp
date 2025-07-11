class Solution {
  public:
    static bool comp(pair<int,int>& x, pair<int,int>&y)
    {
       return (double)x.first/x.second >= (double)y.first/y.second;
         
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        
        vector<pair<int,int>> items;
        for(int i=0;i<val.size();i++)
         items.push_back({val[i],wt[i]});
         
         sort(items.begin(),items.end(),comp);
         double maxTotal=0;
         
         for(int i=0;i<items.size();i++)
         {
             if(items[i].second<=capacity)
             {
                 maxTotal+=items[i].first;
                 capacity-=items[i].second;
             }
             else
             {
               maxTotal+=((double)items[i].first/items[i].second)*capacity;  
               break;
             }
         }
         
       return maxTotal;      
    }

// either sort with max profit first anf=d keep placing maxPrrofit in the array 
//sort with deadline ascending 

class Solution {   
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n=deadline.size();
        int maxProfit=0;
        
        vector<pair<int,int>> jobs;
        for(int i=0;i<n;i++)
         jobs.push_back({deadline[i],profit[i]});
         
         sort(jobs.begin(),jobs.end());
         
          priority_queue<int, vector<int>, greater<int>> pq;
          
          for(const auto& job: jobs)
          {
              if(job.first>pq.size())
               pq.push(job.second);
               
               else if(!pq.empty() && job.second>pq.top())
               {
                    pq.pop();
                   pq.push(job.second);
               }
               
          }
          int cnt=0;
          
          while(!pq.empty())
           {
               maxProfit+=pq.top();
               pq.pop();
               cnt++;
           }
           
           return {cnt,maxProfit};
         
        
    }
};
*******************8888888888888888******************************************************************************************************************




    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n=deadline.size();
        int maxD=*max_element(deadline.begin(),deadline.end());
        
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
         v.push_back({profit[i],deadline[i]});
         
         sort(v.begin(),v.end(),greater<pair<int,int>>());
         
         vector<int> days(maxD+1,-1);
         int cnt=0,maxProfit=0;
         
         for(int i=0;i<n;i++)
         {
             int deadl=v[i].second;
             int profit=v[i].first;
             
             for(int j=deadl;j>0;j--)
             {
                 if(days[j]==-1)
                 {
                     days[j]=1;
                     cnt++;
                     maxProfit+=profit;
                     break;
                 }
             }
             
         }
         
         return {cnt,maxProfit};
    }

*****************************************************************************************************************************************************************************
        for(int i=0;i<n;i++)
         {
             int day=v[i].second;
             int profit=v[i].first;
            //  cout<<"day"<<day<<"profit: "<<profit<<endl;
             while(days[day]!=-1)
             {
                  day--;
             }
             if(day==0)continue;
             days[day]=1;
             cnt++;
             maxProfit+=profit;
         }

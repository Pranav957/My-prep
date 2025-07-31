



class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(int i=0;i<tasks.size();i++)
        {
            freq[tasks[i]-'A']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
    
        int ideals=(freq[0]-1)*n;

        for(int i=1;i<freq.size();i++)
        {
           
            ideals=ideals-min(freq[0]-1,freq[i]);
        }

        return tasks.size()+max(0,ideals);

    }
};

*******************************************************************************
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        for(auto& task: tasks)
        {
            mp[task-'A']++;
        }
       
       int time=0;
       priority_queue<int> pq;

       for(int i=0;i<26;i++)
       {
          if(mp[i]>0)
            pq.push(mp[i]);
       }

       while(!pq.empty())
       {
        vector<int> temp;
          for(int i=1;i<=n+1;i++)
          {
            if(!pq.empty())
            {
                int ele=pq.top();
                pq.pop();
                ele--;
            temp.push_back(ele);
            }
          }

          for(auto &f:temp)
          {
            if(f>0)
             pq.push(f);
          }
          
          if(pq.empty())
             time+=temp.size();
          else
             time+=n+1;  
       }
     return time;
    }
};

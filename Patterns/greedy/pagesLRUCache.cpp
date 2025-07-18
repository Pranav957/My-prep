// User function Template for C++

// User function Template for C++

class Solution {
  public:
    int pageFaults(int N, int C, int pages[]) {
        // code here
        unordered_set<int> st;
        unordered_map<int,int> mp;
        int cnt=0;
      for(int i=0;i<N;i++)
      {
          if(st.size()<C)
           {
               if(st.find(pages[i])==st.end())
               {
                   st.insert(pages[i]);
                   cnt++; 
               }
               mp[pages[i]]=i;
            
           }
           else{
               if(st.find(pages[i])==st.end())
               {
                   int mn=INT_MAX;
                   int val;
                   for(auto it=st.begin();it!=st.end();it++)
                   {
                     if(mp[*it]<mn)
                      {
                          mn=mp[*it];
                          val=*it;
                      }
                   }
                   st.erase(val);
                   st.insert(pages[i]);
                   cnt++;
               }
               mp[pages[i]]=i;
           }
      }
      return cnt; 
    }
};


**************************************************************************************************************************************8
class Solution {
  public:
    int pageFaults(int N, int c, int pages[]) {
        // code here
        queue<int> q;
        unordered_set<int> st;
        int j=0;
        for(int i=0;j<c;i++)
        {
            if(st.find(pages[i])==st.end())
            {
                 st.insert(pages[i]);
                 q.push(pages[i]);
                 j++;
            } 
            
        }
        int count=0;
        
        for(int i=c;i<N;i++)
        {
            if(st.find(pages[i])==st.end())
            {
                int x=q.front();
                q.pop();
                st.erase(x);
                count++;
            }
            else{
                queue<int> newq;
                while(!q.empty() && q.front()!=pages[i])
                {
                     newq.push(q.front());
                     q.pop();
                }
                newq.push(pages[i]);
                q=newq;
                 
            }
        }
        return count+c;
        
         
    }
};

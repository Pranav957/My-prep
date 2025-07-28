class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        map<int,int> mp;

        if(hand.size()%groupSize!=0)
         return false;

         for(int i=0;i<hand.size();i++)
         {
            mp[hand[i]]++;
         }

          while(!mp.empty())
         {
            auto it=mp.begin();
            int curr=it->first;

            for(int j=0;j<groupSize;j++)
            {
              if(mp[curr+j]<1)
               return false;

               mp[curr+j]--;

               if(mp[curr+j]<1)
                mp.erase(curr+j);
            } 
         }
         return true;
        
        

    }
};
*******************************************************************************************************************************************************************
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        map<int,int> mp;

        if(hand.size()%groupSize!=0)
         return false;

         for(int i=0;i<hand.size();i++)
         {
            mp[hand[i]]++;
         }

          while(!mp.empty())
         {
            auto it=mp.begin();
            int curr=it->first;

            for(int j=0;j<groupSize;j++)
            {
               if(mp.find(curr+j)!=mp.end())
               {
                mp[curr+j]--;
                 if(mp[curr+j]==0)
               mp.erase(curr+j);
               }
               else
                return false;
            } 
         }
         return true;
        
        

    }
};

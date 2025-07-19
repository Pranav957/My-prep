class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> mp;
        int amountFive=0;
        int amountTen=0;

        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
               amountFive++;
            else if(10==bills[i] && amountFive>=1)
            {
                  amountFive--;
                  amountTen++;
            }
            else if( amountFive>=1 && amountTen>=1)
            {
                amountFive--;
                amountTen--;
            }
            else if(amountFive>=3) amountFive-=3; 
            else
              {
                return false; 
              }

        }
        return true;
    }
};
********************************************************************************************************************************************************************88
    class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> mp;

        for(int i=0;i<bills.size();i++)
        {
            int remaining=bills[i]-5;
            if(remaining > 0 && mp.empty())
              return false;
            
            for(auto it=mp.rbegin(); it!=mp.rend();it++)
            {
                while(remaining!=0 && remaining>=it->first && it->second>0 )
                {
                    remaining-=it->first;
                    it->second--;
                }
            }
            if(remaining>0)return false;
                    
            mp[bills[i]]++;
        }
        return true;
    }
};

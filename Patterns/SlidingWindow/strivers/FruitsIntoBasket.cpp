
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int> mp;
        int total=0;
        int left=0,r=0;

       for( r=0;r<n;r++)
       {
          mp[fruits[r]]++;
          if(mp.size()<=2)
          {
            total=max(total,r-left+1);
          }
          else
          {
            while(mp.size()>2)
            {
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0)
                 mp.erase(fruits[left]);
                 left++;
            }
          }
           
       }
       
       return total;
    }
};
******************************************************************************************************************
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int> mp;
        int total=0;
        int left=0,r=0;

       for( r=0;r<n;r++)
       {
          mp[fruits[r]]++;
          if(mp.size()<=2)
          {
            total=max(total,r-left+1);
          }
          else
          {
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0)
                 mp.erase(fruits[left]);
                 left++;
          }
           
       }
       
       return total;
    }
};
************************************************************************************************************************************

    
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_set<int> st;
        int total=0;
      for(int i=0;i<n;i++)
      {
        int cnt=0;
        for(int j=i;j<n;j++)
        {
          st.insert(fruits[j]);  
          if(st.size()>2)
           break;  
          cnt++;
        }
        st.clear();
        total=max(total,cnt);
      }
      return total;
    }
};
*********************************************************************************************************************
int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_set<int> st;
        int total=0;
      for(int i=0;i<n;i++)
      {
        for(int j=i;j<n;j++)
        {
          st.insert(fruits[j]);  
          if(st.size()<=2)
           total=max(total,j-i+1);
          else
           break;  
        }
        st.clear();
        
      }
      return total;
    }

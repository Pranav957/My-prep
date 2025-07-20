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

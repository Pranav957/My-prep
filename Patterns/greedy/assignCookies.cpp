class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
       int i=0,j=0;
       while(i<s.size())
       {
          if(s[i]>=g[j])
           j++;

           if(j==g.size())
            break;
          i++; 
       }
       return j;
        
    }
};

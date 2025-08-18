class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        vector<int> knownBy(n,0);
        vector<int> knows(n,0);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(i==j)continue;
                if(mat[i][j]==1)
                {
                   knownBy[j]++;
                   knows[i]++;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(knownBy[i]==n-1 && knows[i]==0)
              return i;
        }
        return -1;
    }
};
************************************************************************************************************************************
class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int up=0;
        int down=mat.size()-1;
        
        while(up<down)
        {
            if(mat[up][down]==1)
             up++;
            else if(mat[down][up]==1)
             down--;
            else
              {
                  up++;
                  down--;
              }
        }
        if(up>down)return -1;
        for(int i=0;i<mat[up].size();i++)
        {
            if(i==up)continue;
            if(mat[up][i]==1 || mat[i][up]==0)
             return -1;
        }
      return up;    
    }
};

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int n=asteroids.size();
        int j=-1;
       for(int i=0;i<n;i++)
       {
          if(asteroids[i]<0)
          {
            while(!ans.empty() && abs(asteroids[i])>ans[j] && ans[j]>0)
             {
                ans.pop_back();
              j--;
             } 
             if(j!=-1 && abs(asteroids[i])<ans[j])
                continue;
             if(j!=-1 && abs(asteroids[i])==ans[j])
               {
                ans.pop_back();
                j--;
                continue;
               }
          }

        ans.push_back(asteroids[i]);
        j++;
       }
       return ans;
    }
};

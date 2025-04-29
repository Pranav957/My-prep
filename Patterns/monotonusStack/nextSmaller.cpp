stack<int> s;
       vector<int> v(nums.size(),-1);
       for(int i=0;i<nums.size();i++)
       {
         while(!s.empty() && nums[i]<nums[s.top()])
         {
            int index=s.top();
            s.pop();
            v[index]=nums[i];
         }
         s.push(i);
       }
        for(int i=0;i<nums.size();i++)
       {
          while(nums[i]>nums[s.top()])
          {
            int index=s.top();
            s.pop();
            v[index]=nums[i];
          }
       } 
      
       return v;

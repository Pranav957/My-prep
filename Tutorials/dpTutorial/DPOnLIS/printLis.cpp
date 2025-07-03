vector<int> dp(n,1), hash(n);
     int maxi=1,lastIndex=0;

     for(int i=0;i<n;i++)
     {
        hash[i]=i;
        for(int prev=0;prev<i;prev++)
        {
            if(nums[i]>nums[prev] && 1+dp[prev]>dp[i] )
             {
                dp[i]=1+dp[prev];
                hash[i]=prev;
             }
        }
        if(dp[i]>maxi)
        {
            maxi=dp[i];
            lastIndex=i;
        }
     }
     return maxi;

       vector<int> temp;
       temp.push_back(nums[lastIndex]);
       while(hash[lastIndex]!=lastIndex)
       {
          temp.push_back(hash[lastIndex]);
          lastIndex=hash[lastIndex];
       }

       for(auto it:temp) cout<<it<<" ";
        
    }

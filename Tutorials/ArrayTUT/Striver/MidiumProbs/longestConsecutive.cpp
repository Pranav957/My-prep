
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=true;
        }
        int i=0, maxi=0;
        while(i<nums.size())
        {
            int cnt=0;
            if(mp[nums[i]]!=false)
            {
                int x=nums[i];
                while(mp.count(x))
                {
                    mp[x]=false;
                    x++;
                    cnt++;
                    
                }
                x=nums[i]-1;
                 while(mp.count(x))
                {
                    mp[x]=false;
                    x--;
                    cnt++; 
                }

            }

            i++;
          maxi=max(maxi,cnt);    
        }
        return maxi;
    }
};
****************************************************************************
  int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    for (auto it : st) {
        if (st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

}
***************************************************
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if (n == 0) return 0;

    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    for (int i = 0; i < n; i++) {
        if (a[i] - 1 == lastSmaller) {
            cnt += 1;
            lastSmaller = a[i];
        }
        else if (a[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;

}

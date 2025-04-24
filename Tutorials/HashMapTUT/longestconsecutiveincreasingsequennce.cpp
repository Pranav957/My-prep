#include<unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
  unordered_map<int,pair<bool,int>> mp;
  vector<int> v;
  for(int i=0;i<n;i++)
  {
      mp[arr[i]].first=true;
      mp[arr[i]].second=i+1;
  }
  int Maxlength=0;
  int starti;
  int endi;
  for(int i=0;i<n;i++)
  {
      if(mp[arr[i]].first==false)
        continue;
      int start=arr[i];
      int end=arr[i];
      int curr;
      int length=1;
     int index;
      for(int j=1;j<n;j++)
      {
          curr=arr[i]+j;
         if(mp.find(curr)!=mp.end())
         {
             length++;
             mp[curr].first=false;
             end=curr;
         }
         else
           break;
      }
      for(int j=1;j<n;j++)
      {
        curr=arr[i]-j;
         if(mp.find(curr)!=mp.end())
         {
             length++;
             mp[curr].first=false;
             start=curr;
             index=j;
         }
         else 
          break;
      }
      arr[i]=false;
      if(length>Maxlength )
        {
            Maxlength=length;
        starti=start;
        endi=end;
       
        }
        else if(length==Maxlength && mp[start].second< mp[starti].second)
        {
          Maxlength = length;
          starti = start;
          endi = end;
        }
       
        
  }
  if(starti==endi)
    v.push_back(starti);
  else
  {
        v.push_back(starti);
    v.push_back(endi);  
  }
  return v;
}


#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
   priority_queue<int,vector<int>,greater<int>> p;
   for(int i=0;i<input.size();i++)
   {
       for(int j=0;j<input[i]->size();j++)
       {
           int x=input[i]->at(j);
          p.push(x);
       }
   }
   vector<int> v;
  while(!p.empty())
  {
      v.push_back(p.top());
      p.pop();
  }
  return v;
}

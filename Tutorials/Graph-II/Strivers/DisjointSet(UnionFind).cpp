// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>         //O(4alpha) ~=O(1))
using namespace std;
class Disjoinset{
    vector<int> rank, parent,size;
    public:
     Disjoinset(int n)
     {
         rank.resize(n+1,0);
         parent.resize(n+1);
         size.resize(n+1);
         for(int i=0;i<n+1;i++)
         {
               parent[i]=i;
               size[i]=1;
         }
     }
     
     int findUParent(int node)
     {
         if(node==parent[node])
           return node;
          
         return parent[node]=findUParent(parent[node]);  
     }
     
     void unionByRank(int u,int v)
     {
         int ulp_u= findUParent(u);
         int ulp_v=findUParent(v);
         
         if(ulp_u==ulp_v) return;
         
         if(rank[ulp_u]>rank[ulp_v])
         {
             parent[ulp_v]=ulp_u;
         }
         else if(rank[ulp_u]<rank[ulp_v])
         {
             parent[ulp_u]=ulp_v;
         }
         else
          {
               parent[ulp_v]=ulp_u;
               rank[ulp_u]++;
          }
     }
     
     void unionBySize(int u,int v)
     {
         int ulp_u= findUParent(u);
         int ulp_v=findUParent(v);
         
         if(ulp_u==ulp_v) return;
         
         if(size[ulp_u]>size[ulp_v])
         {
             parent[ulp_v]=ulp_u;
             size[ulp_u]++;
         }
         else
         {
             parent[ulp_u]=ulp_v;
             size[ulp_v]++;
         }
     }
};

int main() {
    Disjoinset d(7);
    d.unionBySize(1,2);
    d.unionBySize(2,3);
    d.unionBySize(4,5);
    d.unionBySize(6,7);
    d.unionBySize(5,6);
    if(d.findUParent(3)==d.findUParent(7))
      cout<<"same";
    else
     cout<< "Not same";
    d.unionBySize(3,7);
     if(d.findUParent(3)==d.findUParent(7))
      cout<<"same";
    else
     cout<< "Not same";

    return 0;
}

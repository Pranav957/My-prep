/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


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
             size[ulp_u]+=size[ulp_v];
         }
         else
         {
             parent[ulp_u]=ulp_v;
             size[ulp_v]+=size[ulp_u];
         }
     }
};
class Solution{
public:
vector<int> numOfIslands(int n, int m, vector<vector<int>> &A){
       int k=A.size();
        Disjoinset ds(n*m);
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> ans;

         int diffX[4]={-1, 0, 1,0};
         int diffY[4]={0,1,0,-1};
    
        int cnt=0;

        for(auto it: A)
        {
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1)
            {
                ans.push_back(cnt);
                continue;
            }  
            else{
               vis[row][col]=1;
               cnt++;

              for(int i=0;i<4;i++)
              {
                int addR=diffX[i]+row;
                int addC=diffY[i]+col;

                if(addR>=0 && addR<n && addC>=0 && addC<m)
                {
                    if(vis[addR][addC]==1)
                    {
                        int nodeNo= row*m+col;
                        int addRNo=addR*m+addC;
                        if(ds.findUParent(nodeNo)!=ds.findUParent(addRNo))
                        {
                            cnt--;
                            ds.unionBySize(nodeNo,addRNo);
                        }
                    }

                }
              }
              ans.push_back(cnt);
            }  
        }
        return ans;
    }
};
int main()
{
   int n = 4, m = 5, k = 12; 
   Solution s;
   vector<vector<int>>A = {{0,0},{0,0},{1,1},{1,0},{0,1},{0,3},{1,3},{0,4}, {3,2}, {2,2},{1,2}, {0,2}};
   vector<int> ans=s.numOfIslands(n,m,A);
   for(auto it:ans)
   {
       cout<<it<<" ";
   }
}

// User function Template for C++
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
class Solution {
  public:
    static bool comp(vector<int>& v1, vector<int>& v2)
    {
        return v1[2]<v2[2];
    }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        // vector<pair<int,pair<int,int>>> edges 
        
        sort(edges.begin(),edges.end(),comp);
        Disjoinset ds(V);
        int mstWt=0;
        
        for(auto edge: edges)
        {
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            if(ds.findUParent(u)!=ds.findUParent(v))
            {
                mstWt+=wt;
                ds.unionBySize(u,v);
            }
        }
        
        return mstWt;
        
    }
};

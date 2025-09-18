bool helper(vector<vector<int>>& graph, vector<int>& color, int cl, int sv) {
    color[sv] = cl;

    for (int neighbor : graph[sv]) {
        if (color[neighbor] == cl)
            return false;
        if (color[neighbor] == -1) {
            if (!helper(graph, color, !cl, neighbor))
                return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1);
    for(int i = 0; i < n; i++) {
        if(color[i] == -1) {  // <-- Fixed condition here
            if(helper(graph, color, 0, i) == false)
                return false;
        }  
    }
    return true;
}
******************************************************************************
class Solution {
public:

   bool helper(vector<vector<int>>& graph,int n,vector<int>& color,int cl,int sv)
   {
      color[sv]=cl;

      for(int i=0;i<n;i++)
      {
        if(graph[sv][i]==1 )
         {
            if(color[i]==cl)
             return false;
           if(color[i]==-1) 
            {
            bool res= helper(graph,n,color,!cl,i);
            if(res==false)
             return false;
            }
         } 
      }
      return true;
   }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(helper(graph,n,color,0,i)==false)
                 return false;
            }  
        }
        return true;
    }
};

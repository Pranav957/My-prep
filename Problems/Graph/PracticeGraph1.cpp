/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void pringDfs(int** edges,int n, bool* visited,int sv)
{
    cout<<sv<<" ";
    visited[sv]=true;
    
    for(int i=0;i<n;i++)
    {
        if(edges[sv][i]==1 && !visited[i])
        {
            pringDfs(edges,n,visited,i);
        }
    }
}

bool hasPath(int** edges,int n,bool* visited,int sv,int ed)
{
    if(sv>=n || ed>=n)
     return false;
     
     if(sv==ed)
      return true;
     
     visited[sv]=true;
     
     for(int i=0;i<n;i++)
     {
         if(!visited[i] && edges[sv][i]==1)
         {
              bool res= hasPath(edges,n,visited,i,ed);
              if(res)
               return res;
         } 
           
           
     }
     return false;
     
}

vector<int>* getpathDfs(int** edges,int n,bool* visited,int sv,int ev)
{
      if(sv>=n || ev>=n)
     return NULL;
     
     if(sv==ev)
     {
         vector<int>* v=new vector<int>();
         v->push_back(ev);
         return v;
     }
     
     visited[sv]=true;
     
     for(int i=0;i<n;i++)
     {
         if(!visited[i] && edges[sv][i]==1)
         {
             vector<int> *res=getpathDfs(edges,n,visited,i,ev);
             if(res!=NULL)
            {
                res->push_back(sv);
              return res;
            }  
         }
     }
     
     return NULL;
     
}

bool hasPathBfs(int** edges,int n,bool* visited,int sv,int ev)
{
    if(sv>=n || ev>=n)
     return false;
     
    queue<int> pendingVertices;
    
    pendingVertices.push(sv);
    visited[sv]=true;
    
    while(!pendingVertices.empty())
    {
        int index=pendingVertices.front();
        pendingVertices.pop();
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i] && edges[index][i]==1)
            {
                if(i==ev)
                 return true;
                 
                bool res= hasPathBfs(edges,n,visited,i,ev);
                if(res) return true;
            }
        }
    }
    return false;
}

vector<int>* getpathBfs(int** edges,int n,bool* visited,int sv,int ev)
{
    if(sv>=n || ev>=n)
     return NULL;
     
      queue<int> pendingVertices;
      
      pendingVertices.push(sv);
      visited[sv]=true;
      
      unordered_map<int,int> mp;
      
      while(!pendingVertices.empty())
      {
          int index=pendingVertices.front();
          pendingVertices.pop();
          
          if(index==ev)
                  {
                      vector<int>* v=new vector<int>();
                      v->push_back(ev);
                    //   v->push_back(index);
                      int curr=ev;
                      while(curr!=sv)
                      {
                          v->push_back(mp[curr]);
                          curr=mp[curr];
                      }
                      return v;
                  }
          
          for(int i=0;i<n;i++)
          {
              if(!visited[i] && edges[index][i]==1)
              {
                //   if(i==ev)
                //   {
                //       vector<int>* v=new vector<int>();
                //       v->push_back(ev);
                //       v->push_back(index);
                //       int curr=index;
                //       while(curr!=sv)
                //       {
                //           v->push_back(mp[curr]);
                //           curr=mp[curr];
                //       }
                //       return v;
                //   }
                  pendingVertices.push(i);
                  visited[i]=true;
                  mp[i]=index;
              }
              
          }
      }
      return NULL;
}


void printBfs(int** edges,int n, bool* visited,int sv)
{
    queue<int> pendingVertices;
    
    pendingVertices.push(sv);
    visited[sv]=true;
    
    while(!pendingVertices.empty())
    {
        int vertex =pendingVertices.front();
        pendingVertices.pop();
        cout<<vertex<<" ";
        
        for(int i=0;i<n;i++)
        {
            if(edges[vertex][i]==1 && !visited[i])
             {
                 pendingVertices.push(i);
                 visited[i]=true;
             }
        }
        
    }
}

int main()
{
   int n,e;
   cin >> n >> e;
   
   int** edges=new int*[n];
   for(int i=0;i<n;i++)
   {
       edges[i]=new int[n];
   }
   
   for(int i=0;i<e;i++)
   {
       int first,second;
       cin >> first >> second;
       
       edges[first][second]=1;
       edges[second][first]=1;
   }
   
   bool * visited=new bool[n];
   
   for(int i=0;i<n;i++)
     visited[i]=false;
    
    //  pringDfs(edges,n,visited,0);
     cout<<endl;
    //  printBfs(edges,n,visited,0);
     
    //  int sv,ev;
    //  cin >> sv >> ev;
     
    //  bool path=hasPathBfs(edges,n,visited,sv,ev);
    //  if(path)
    //   cout<<"true"<<" ";
    //  else
    //   cout<< "false"<<" ";
    
    // vector<int>* path=getpathBfs(edges,n,visited,sv,ev);
    
//   if(path!=NULL)
//     {
//          for(int i=0;i<path->size();i++)
//           cout<<path->at(i)<<" ";
//     }

// pringDfs(edges,n,visited,0);
int count=0;

    for(int i=0;i<n;i++)
    { 
      if(visited[i]==false)
       {
            // cout<<"NOT Connected"<<" ";
            // return 0;
             cout<<"Component: ";
            pringDfs(edges,n,visited,i);
            count++;
           
       }
    }
    
    cout<<"Connected Graph"<<" and no of compents "<<count<<" ";
    
     
     delete [] visited;
     
     for(int i=0;i<n;i++)
       delete [] edges[i];
       
       delete [] edges;
                            // 5 4 0 1 1 2 2 3 3 0
    return 0;
}

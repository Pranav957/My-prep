vector<int>* getDFSPath(int**edges,int n,bool * visited, int v1,int v2)
{
       if(v1==v2)
            {
                vector<int>* path=new vector<int>();
                path->push_back(v2);
                return path;
            } 
    visited[v1]=true;
   for(int i=0;i<n;i++)
   {
         if(edges[v1][i]==1 && !visited[i])
        {
                vector<int>* path=getDFSPath(edges,n,visited,i,v2);
            if(path!=NULL)
            {
                path->push_back(v1);
                return path;
            }
        }
   }
   return NULL;
}

int main() {
    // Write your code here
    int n,e;
   cin >> n>> e;
    int ** edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for (int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++)
    {
        int f,s;
        cin >> f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    
    bool* visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }

   int v1,v2;
   cin >> v1>>v2;
    vector<int>* path=getDFSPath(edges,n,visited,v1,v2);
    if(path==NULL)
      return 0;
    for(int i=0;i<path->size();i++)
    {
        cout<<path->at(i)<<" ";
    }
    delete [] visited;
    for(int i=0;i<n;i++)
    {
        delete []edges[i];
    }
    delete[] edges;
}

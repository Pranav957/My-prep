//*****************************KRUSKALS ALGO*********************************************
#include <iostream>
#include <algorithm> // for std::sort
using namespace std;

class Edge{
    public:
   int source;
   int dest;
   int weight;

   Edge(){

   }
   Edge(int s, int d, int w)
   {
       source=s;
       dest=d;
       weight=w;
   }
};

bool sortByEdge(Edge& x, Edge& y)
{
    return x.weight<y.weight;
}
int find(int* parent, int v1)
{
    if(parent[v1]==v1)
      return v1;

      return find(parent,parent[v1]);
}

int main() {
    // Write your code here
    int n,e;
    cin >> n >>e;

    Edge* input= new Edge[e];
    Edge* output=new Edge[n-1];

    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cin >> s >>d>>w;
        Edge x(s,d,w);
        input[i]=x;
    }

    sort(input, input+e, sortByEdge);

    int * parent=new int[n];

    for(int i=0;i<n;i++)
      parent[i]=i;

      int count=0;

      for(int i=0;i<e;i++)
      {
          Edge x=input[i];
          int source=x.source;
          int dest=x.dest;

          int parentv1=find(parent,source);
          int parentv2=find(parent, dest);

          if(parentv1!=parentv2)
          {
              output[count]=x;
              count++;
              parent[parentv1]=parentv2;
          }
          if(count==n-1)
            break;
      }

      for(int i=0;i<n-1;i++)
      {
          if(output[i].source<output[i].dest)
               cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
          else
                 cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
      }
      delete [] input;
      delete [] output;
      delete [] parent;
      return 0;

}

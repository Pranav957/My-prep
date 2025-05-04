






/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
class Edges{
    public:
     int source;
     int dest;
     int weight;
     
     Edges() {}
     
     Edges(int s,int d,int w)
     {
         source=s;
         dest=d;
         weight=w;
     }
};

int findParent(int v1,int* parent)
{
    while(parent[v1]!=v1)
      v1=parent[v1];
      
      return v1;
}

bool compareByWeight(const Edges& x,const Edges& y)
{
    return x.weight<y.weight;
}

void KruskalsAlgo(Edges* input,Edges* output,int* parent,int n,int e)
{
     sort(input,input+e,compareByWeight);
     int count=0;
    
    for(int i=0;i<e;i++)
    {
        Edges x=input[i];
        
        int vertex1=x.source;
        int vertex2=x.dest;
        
        int parentv1=findParent(vertex1,parent);
         int parentv2=findParent(vertex2,parent);
        
        if(parentv1!=parentv2)
        {
            output[count]=x;
            count++;
            
            parent[parentv1]=parentv2;
            
            if(count==n-1)
             break;
        }
    }
}

int main()
{
    int n, e;
    cin >> n>> e;
    
    Edges* input=new Edges[e];
    Edges* output=new Edges[n-1];
    
    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cin >> s >> d >> w;
        Edges x(s,d,w);
        input[i]=x;
    }
    
    int* parent=new int[n];
    
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    
    KruskalsAlgo(input,output,parent,n,e);
    
    cout<<"result: "<<endl; //5 4 0 1 5 1 2 6 2 3 2 3 0 4
    
    for(int i=0;i<n-1;i++)
    {
        Edges x=output[i];
        cout<<x.source<<" "<<x.dest<<" "<<x.weight<<endl;  // 
    }
    
    delete [] input;
    delete [] output;
    delete [] parent;
    
    return 0;
    
}










<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

#include <iostream>
#include <algorithm> // for std::sort
using namespace std;


class Edge
{
public:
    int source;
    int dest;
    int weight;
    Edge(){}
    Edge(int s,int d,int w)
    {
        source=s;
        dest=d;
        weight=w;
    } 
};

bool compareEdgesByWeight(const Edge& edge1, const Edge& edge2) {
    return edge1.weight < edge2.weight;
}

int find(int* parent, int v) {
    if (parent[v] == v)
        return v;
    return find(parent, parent[v]);
}

int main() {
    int n, e;
    cin >> n >> e;
    Edge *input = new Edge[e];
    Edge* output = new Edge[n-1];
    for(int i=0;i<e;i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        Edge x(s, d, w);
        input[i] = x;
    }

    sort(input, input+e, compareEdgesByWeight);
    int* parent = new int[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    int count = 0;

    for (int i = 0; i < e; i++)
    {
        Edge x = input[i];
        int v1 = x.source;
        int v2 = x.dest;
        int parentV1 = find(parent, v1);
        int parentV2 = find(parent, v2);
        if(parentV1 != parentV2)
        {
            output[count] = x;
            count++;
            parent[parentV1] = parentV2;
        }
        if(count == n-1)
            break;
    }

    for(int i=0; i<n-1; i++)
    {
        if(output[i].source < output[i].dest)
        {
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
        }
        else
        {
            cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
        }
    }

    delete[] input;
    delete[] output;
    delete[] parent;
    return 0;
}

/*

#include <iostream>
#include <algorithm> // for std::sort
using namespace std;

class Edge {
public:
    int source;
    int dest;
    int weight;
    Edge() {}
    Edge(int s, int d, int w) {
        source = s;
        dest = d;
        weight = w;
    }
};

bool compareEdgesByWeight(const Edge& edge1, const Edge& edge2) {
    return edge1.weight < edge2.weight;
}

int find(int* parent, int v) {
    if (parent[v] == v)
        return v;
    return find(parent, parent[v]);
}

void unionSet(int* parent, int v1, int v2) {
    int parentV1 = find(parent, v1);
    int parentV2 = find(parent, v2);
    parent[parentV1] = parentV2;
}

int main() {
    int n, e;
    cin >> n >> e;
    Edge* input = new Edge[e];
    Edge* output = new Edge[n - 1];
    for (int i = 0; i < e; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        Edge x(s, d, w);
        input[i] = x;
    }
    sort(input, input + e, compareEdgesByWeight);
    int* parent = new int[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    int count = 0;
    for (int i = 0; i < e; i++) {
        Edge x = input[i];
        int v1 = x.source;
        int v2 = x.dest;
        int parentV1 = find(parent, v1);
        int parentV2 = find(parent, v2);
        if (parentV1 != parentV2) {
            output[count] = x;
            count++;
            unionSet(parent, v1, v2);
            if (count == n - 1)
                break;
        }
    }
    // print the output edges
     for(int i=0;i<n-1;i++)
     {
         if(output[i].source < output[i].dest)
          {
              cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
          }
          else
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
     }
    delete[] input;
    delete[] output;
    delete[] parent;
    return 0;
}


/*
class Edge
{
   public:
     int source;
     int dest;
     int weight;
     Edge(){}
    Edge(int s,int d,int w)
    {
        source=s;
        dest=d;
        weight=w;
    } 
};
bool compareEdgesByWeight(const Edge& edge1, const Edge& edge2) {
    return edge1.weight < edge2.weight;
}
//wrong code
int main() {
    // Write your code here
    cout<<"hi";
    int n, e;
    cin >> n >> e;
     Edge *input= new Edge[e];
     Edge* output= new Edge[n-1];
      cout<<"hi";
     for(int i=0;i<e;i++)
     {
         int s,d,w;
         cin>>s >> d >> w;
         Edge x;
         x.source=s;
         x.dest=d;
         x.weight=w;
         input[i]=x;
     }
     
     sort(input,input+e,compareEdgesByWeight);
     int* parent= new int[n];
     int count=0;
     while(count<n-1)
     {
       for (int i = 0; i < e; i++)
        {
         Edge x = input[i];
         int v1=x.source;
         int v2=x.dest;
         int parentV1=parent[v1];
         int parentV2=parent[v2];
         if(parentV1!=parentV2)
         {
             output[i]=x;
             count++;
             parent[parentV1]=parentV2;
         }
         if(count==n-1)
           break;
       }
     }
     
}
*/

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
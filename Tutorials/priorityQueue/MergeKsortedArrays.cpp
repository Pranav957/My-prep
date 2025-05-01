
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

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    #include <vector>
#include <queue>
using namespace std;

// Define a struct to hold value along with array and element indices
struct HeapNode {
    int value;
    int arrayIndex;
    int elementIndex;

    HeapNode(int val, int i, int j) : value(val), arrayIndex(i), elementIndex(j) {}

    // Min-heap comparator
    bool operator>(const HeapNode& other) const {
        return value > other.value;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>*>& input) {
    // Min-heap (priority_queue with custom comparator)
    priority_queue<HeapNode, vector<HeapNode>, greater<HeapNode>> minHeap;

    // Push first element of each array into the heap
    for (int i = 0; i < input.size(); i++) {
        if (!input[i]->empty()) {
            minHeap.emplace((*input[i])[0], i, 0);
        }
    }

    vector<int> result;

    // Extract min and push the next element from same array
    while (!minHeap.empty()) {
        HeapNode curr = minHeap.top();
        minHeap.pop();
        result.push_back(curr.value);

        int nextIndex = curr.elementIndex + 1;
        if (nextIndex < input[curr.arrayIndex]->size()) {
            minHeap.emplace((*input[curr.arrayIndex])[nextIndex], curr.arrayIndex, nextIndex);
        }
    }

    return result;
}
O(nlogk)

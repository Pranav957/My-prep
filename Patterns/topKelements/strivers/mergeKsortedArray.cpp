class Solution {
  public:
    // Function to merge k sorted arrays.
//     vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
//         // code here
//       priority_queue< 
//     pair<int, pair<int, int>>, 
//     vector<pair<int, pair<int, int>>>, 
//     greater<pair<int, pair<int, int>>> 
// > pq;
//         for(int i=0;i<arr.size();i++)
//         {
//             pq.push({arr[i][0],{i,0}});
//         }
//         vector<int> ans;
        
//         while(!pq.empty())
//         {
//             auto top = pq.top();
//             int val = top.first;
//             int arrIdx = top.second.first;
//             int eleIdx = top.second.second;
//             pq.pop();
//             ans.push_back(val);
//             if(eleIdx+1<arr[arrIdx].size())
//               pq.push({arr[arrIdx][eleIdx+1],{arrIdx,eleIdx+1}});
//         }
//         return ans;
//     }
  vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        priority_queue< 
            pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>> 
        > pq;

        for (int i = 0; i < arr.size(); i++) {
            if (!arr[i].empty())
                pq.emplace(arr[i][0], make_pair(i, 0));
        }

        vector<int> ans;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int val = top.first;
            int arrIdx = top.second.first;
            int eleIdx = top.second.second;

            ans.push_back(val);

            if (eleIdx + 1 < arr[arrIdx].size()) {
                pq.emplace(arr[arrIdx][eleIdx + 1], make_pair(arrIdx, eleIdx + 1));
            }
        }

        return ans;
    }
};

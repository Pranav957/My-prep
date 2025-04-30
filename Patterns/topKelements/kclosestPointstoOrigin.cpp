vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // max-heap: pair<distance squared, index>
    priority_queue<pair<int, vector<int>>> maxHeap;

    for (auto& point : points) {
        int x = point[0], y = point[1];
        int distSq = x * x + y * y;

        maxHeap.push({distSq, point});
        if (maxHeap.size() > k) {
            maxHeap.pop();  // remove farthest
        }
    }

    vector<vector<int>> res;
    while (!maxHeap.empty()) {
        res.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return res;
}

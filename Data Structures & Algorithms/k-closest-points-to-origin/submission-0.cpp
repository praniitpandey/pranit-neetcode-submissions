class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, pair<int,int>>> maxHeap;

        for (vector<int> point : points) {
            int distance2 = point[0] * point[0] + point[1] * point[1];
            maxHeap.push({distance2, {point[0], point[1]}});

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> solution;

        while (!maxHeap.empty()) {
            solution.push_back({maxHeap.top().second.first, maxHeap.top().second.second});
            maxHeap.pop();
        }

        return solution;
    }
};

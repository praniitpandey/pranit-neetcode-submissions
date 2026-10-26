class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](vector<int>& point1, vector<int>& point2) {
            long long distance1 = (point1[0] * point1[0]) + (point1[1] * point1[1]);
            long long distance2 = (point2[0] * point2[0]) + (point2[1] * point2[1]);

            return distance1 < distance2;
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> maxHeap(cmp);

        for (vector<int>& point : points) {
            maxHeap.push(point);

            if (maxHeap.size() > k) 
                maxHeap.pop();
        }

        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top());
            maxHeap.pop();
        }

        return res;
    }
};

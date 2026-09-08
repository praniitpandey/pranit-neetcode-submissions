class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == n) return 0;

        vector<long long> pairSums;
        for (int i = 1; i < n; i++)
            pairSums.push_back(weights[i - 1] + weights[i]);

        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int pairSum : pairSums) {
            minHeap.push(pairSum);
            maxHeap.push(pairSum);

            if (minHeap.size() > k - 1) minHeap.pop();
            if (maxHeap.size() > k - 1) maxHeap.pop();
        }

        long long ans = 0;
        while (!minHeap.empty()) {
            ans += (minHeap.top() - maxHeap.top());
            minHeap.pop();
            maxHeap.pop();
        }

        return ans;
    }
};
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        // Create pairs: {nums2[i], nums1[i]}
        vector<pair<int, int>> nums;

        for (int i = 0; i < n; i++) {
            nums.push_back({nums2[i], nums1[i]});
        }

        // Sort by nums2 in descending order
        sort(nums.rbegin(), nums.rend());

        // Min-heap to maintain the k largest nums1 values
        priority_queue<int, vector<int>, greater<int>> minHeap;

        long long sum = 0;
        long long bestScore = 0;

        for (int i = 0; i < n; i++) {
            int num2 = nums[i].first;
            int num1 = nums[i].second;

            minHeap.push(num1);
            sum += num1;

            // Keep only the k largest nums1 values
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            // Calculate score when exactly k elements are selected
            if (minHeap.size() == k) {
                bestScore = max(bestScore, sum * num2);
            }
        }

        return bestScore;
    }
};
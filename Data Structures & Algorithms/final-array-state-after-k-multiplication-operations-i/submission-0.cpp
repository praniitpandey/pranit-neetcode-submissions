class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        auto cmp = [](pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            else {
                return a.first > b.first;
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);

        for (int i = 0; i < nums.size(); i++) {
            minHeap.push(make_pair(nums[i], i));
        }

        for (int i = 0; i < k; i++) {
            auto [value, index] = minHeap.top();
            minHeap.pop();
            minHeap.push(make_pair(value * multiplier, index));
        }

        while (!minHeap.empty()) {
            auto [value, index] = minHeap.top();
            minHeap.pop();

            nums[index] = value;
        }

        return nums;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int n = nums.size();
        vector<int> ans;
        for (int r = 0; r < k && r < n; r++) {
            pq.push(make_pair(nums[r], r));
        }
        ans.push_back(pq.top().first);

        for (int r = k; r < n; r++) {
            pq.push(make_pair(nums[r], r));
            while (!pq.empty() && pq.top().second < (r - k + 1))
                pq.pop();
            ans.push_back(pq.top().first);
        }

        return ans;        
    }
};
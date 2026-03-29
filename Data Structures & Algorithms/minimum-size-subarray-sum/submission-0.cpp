class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, ans = INT_MAX;
        long long sum = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum >= target) {
                sum -= nums[left];
                ans = min(ans, right - left + 1);
                ++left;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
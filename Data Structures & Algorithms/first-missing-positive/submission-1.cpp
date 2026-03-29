class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) nums[i] = n + 1;
        }

        for (int i = 0; i < n; i++) {
            int value = abs(nums[i]);

            if (value > 0 && value <= n && nums[value - 1] > 0) {
                nums[value - 1] *= -1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return (i + 1);
            }
        }

        return (n + 1);
    }
};
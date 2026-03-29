class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_ending_here = nums[0], max_overall = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            max_ending_here = max(nums[i], max_ending_here + nums[i]);
            max_overall = max(max_ending_here, max_overall);
        }

        return max_overall;
    }
};

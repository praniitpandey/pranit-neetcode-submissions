class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        else if (n == 2) {
            return max(nums[0], nums[1]);
        }

        int max_ending_at_i_minus_2 = nums[0], 
            max_ending_at_i_minus_1 = max(nums[0], nums[1]),
            max_ending_at_i = 0,
            max_overall = 0;

        for (int i = 2; i < n; i++) {
            max_ending_at_i = max(max_ending_at_i_minus_1, nums[i] + max_ending_at_i_minus_2);
            max_ending_at_i_minus_2 = max_ending_at_i_minus_1;
            max_ending_at_i_minus_1 = max_ending_at_i;

            max_overall = max(max_ending_at_i, max_overall);
        }

        return max_overall;                
    }
};
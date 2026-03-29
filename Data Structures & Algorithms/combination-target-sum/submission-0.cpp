class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> sums;
        generate(nums, target, 0, vector<int>{}, sums);

        return sums;        
    }

    void generate(const vector<int>& nums, int target, int index, vector<int> sum, vector<vector<int>>& sums) {
        if (index == nums.size()) {
            if (target == 0) {
                sums.push_back(sum);
            }
        }
        else {
            while (target >= 0) {
                generate(nums, target, index + 1, sum, sums);
                target -= nums[index];
                sum.push_back(nums[index]);
            }
        }
    }
};
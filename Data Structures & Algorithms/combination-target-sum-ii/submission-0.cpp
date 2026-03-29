class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sums;
        generate(nums, target, 0, vector<int>{}, sums);
        
        set<vector<int>> sumSet(sums.begin(), sums.end());

        return vector<vector<int>>(sumSet.begin(), sumSet.end());
    }

    void generate(const vector<int>& nums, int target, int index, vector<int> sum, vector<vector<int>>& sums) {
        if (index == nums.size()) {
            if (target == 0) {
                sums.push_back(sum);
            }
        }
        else {
            generate(nums, target, index + 1, sum, sums);
            if (target >= nums[index]) {
                sum.push_back(nums[index]);
                generate(nums, target - nums[index], index + 1, sum, sums);
            }
        }
    }
};
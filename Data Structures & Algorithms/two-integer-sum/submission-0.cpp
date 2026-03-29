class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diff;
        vector<int> solution;
        for (int i = 0; i < nums.size(); i++) {
            if (diff.find(nums[i]) != diff.end()) {
                solution.push_back(diff[nums[i]]);
                solution.push_back(i);
                break;
            }
            diff[(target - nums[i])] = i;
        }
        return solution;
    }
};

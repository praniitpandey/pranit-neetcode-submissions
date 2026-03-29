class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 == 1) {
            return false;
        }
        else {
            vector<vector<int>> cache(nums.size(), vector<int>(sum/2 + 1, -1));
            return subsetSum(nums, 0, sum/2, cache);
        }
    }
private:
    bool subsetSum(const vector<int>& nums, int i, int target, vector<vector<int>>& cache) {
        if (target == 0) return true;
        if (i == nums.size()) {
            return target == 0;
        }
        else if (cache[i][target] != -1) {
            return (cache[i][target] == 1);
        }
        bool ifNotPicked = subsetSum(nums, i + 1, target, cache);
        bool ifPicked = (nums[i] > target) ? false : subsetSum(nums, i + 1, target - nums[i], cache);
        
        bool result = ifNotPicked || ifPicked;
        cache[i][target] = result ? 1 : 0;

        return result;
    }
};
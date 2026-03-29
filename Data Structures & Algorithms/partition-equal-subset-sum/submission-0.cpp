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
            return subsetSum(nums, 0, sum/2);
        }
    }
private:
    bool subsetSum(const vector<int>& nums, int i, int target) {
        if (i == nums.size()) {
            return target == 0;
        }
        bool ifNotPicked = subsetSum(nums, i + 1, target);
        bool ifPicked = (nums[i] > target) ? false : subsetSum(nums, i + 1, target - nums[i]);

        return ifNotPicked || ifPicked;
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        vector<vector<int>> cache(coins.size(), vector<int>(amount + 1, -1));
        return dfs(0, coins, amount, cache);        
    }

    int dfs(int index, const vector<int>& nums, int target, vector<vector<int>>& cache) {
        if (target == 0) return 1;
        if (index == nums.size()) return 0;
        
        if (cache[index][target] != -1) {
            return cache[index][target];
        }

        int ifNotPicked = dfs(index + 1, nums, target, cache);
        int ifPicked = 0;

        if (nums[index] <= target) {
            ifPicked = dfs(index, nums, target - nums[index], cache);
        }

        return cache[index][target] = ifPicked + ifNotPicked;
    }
};
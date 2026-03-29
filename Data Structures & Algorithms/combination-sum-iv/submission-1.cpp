class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> cache(target + 1, -1);
        return dfs(nums, target, cache);
    }
private:
    int dfs(const vector<int>& nums, int target, vector<int>& cache) {
        if (target == 0) {
            return 1;
        }
        if (cache[target] != -1) {
            return cache[target];
        }
        int count = 0;
        for (int num : nums) {
            if (num <= target) {
                count += dfs(nums, target - num, cache);
            }
        }
        cache[target] = count;
        return count;
    }
};
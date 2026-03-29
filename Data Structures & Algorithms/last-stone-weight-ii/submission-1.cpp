class Solution {
private:
    vector<vector<int>> cache;
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int stone : stones) {
            sum += stone;
        }

        int target = (sum + 1) / 2;
        cache = vector<vector<int>>(stones.size(), vector<int>(target + 1, -1));
        return dfs(stones, 0, 0, sum, target);
    }

private:
    int dfs(const vector<int>& nums, int index, int sumSoFar, int sum, int target) {
        if (sumSoFar >= target || index == nums.size()) {
            return abs(sumSoFar - (sum - sumSoFar));
        }
        if (cache[index][sumSoFar] != -1) {
            return cache[index][sumSoFar];
        }

        int ifNotPicked = dfs(nums, index + 1, sumSoFar, sum, target);
        int ifPicked = dfs(nums, index + 1, sumSoFar + nums[index], sum, target);

        return cache[index][sumSoFar] = min(ifPicked, ifNotPicked);
    }
};
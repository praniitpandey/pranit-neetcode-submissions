class Solution {
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        vector<vector<int>> cache(capacity + 1, vector<int>(weight.size(), -1));
        return dfs(profit, weight, capacity, 0, cache);
    }
    int dfs(vector<int>& profit, vector<int>& weight, int capacity, int index, vector<vector<int>>& cache) {
        if (index >= weight.size() || capacity == 0) {
            return 0;
        }
        else if (cache[capacity][index] != -1) {
            return cache[capacity][index];
        }
        else if (weight[index] > capacity) {
            cache[capacity][index] = dfs(profit, weight, capacity, ++index, cache);
            return cache[capacity][index];
        }
        else {
            int ifPicked = profit[index] + dfs(profit, weight, capacity - weight[index], index + 1, cache);
            int ifNotPicked = dfs(profit, weight, capacity, index + 1, cache);

            cache[capacity][index] = max(ifPicked, ifNotPicked);
            return cache[capacity][index];
        }
    }
};

class Solution {
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        vector<unordered_map<int, int>> cache(profit.size());
        return dfs(profit, weight, 0, capacity, cache);
    }
    int dfs(const vector<int>& profit, const vector<int>& weight, int index, int capacity, vector<unordered_map<int, int>>& cache) {
        if (index == profit.size() || capacity == 0) {
            return 0;
        }
        if (cache[index].find(capacity) != cache[index].end()) {
            return cache[index][capacity];
        }
        int ifNotPicked = dfs(profit, weight, index + 1, capacity, cache);
        int ifPicked = INT_MIN;

        if (weight[index] <= capacity) {
            ifPicked = profit[index] + dfs(profit, weight, index, capacity - weight[index], cache);
        }

        cache[index][capacity] = max(ifNotPicked, ifPicked);

        return cache[index][capacity];
    }

};

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> cache(costs.size(), vector<int>(3, -1));
        int ifRed = dfs(costs, 0, 0, cache);
        int ifBlue = dfs(costs, 0, 1, cache);
        int ifGreen = dfs(costs, 0, 2, cache);

        return min({ifRed, ifBlue, ifGreen});
    }
    int dfs(const vector<vector<int>>& costs, int index, int currentColor, vector<vector<int>>& cache) {
        if (index == costs.size()) {
            return 0;
        }

        if (cache[index][currentColor] != -1) {
            return cache[index][currentColor];
        }

        int ifRed = 1e9, ifBlue = 1e9, ifGreen = 1e9;
        if (currentColor == 0) {
            ifBlue = costs[index][0] + dfs(costs, index + 1, 1, cache);
            ifGreen = costs[index][0] + dfs(costs, index + 1, 2, cache);
        }   //currentColor is RED
        else if (currentColor == 1) {
            ifBlue = costs[index][1] + dfs(costs, index + 1, 0, cache);
            ifGreen = costs[index][1] + dfs(costs, index + 1, 2, cache);
        }   //currentColor is BLUE
        if (currentColor == 2) {
            ifBlue = costs[index][2] + dfs(costs, index + 1, 0, cache);
            ifGreen = costs[index][2] + dfs(costs, index + 1, 1, cache);
        }   //currentColor is GREEN

        cache[index][currentColor] = min({ifRed, ifBlue, ifGreen});
        return cache[index][currentColor];
    }
};
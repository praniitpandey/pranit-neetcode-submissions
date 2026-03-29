class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<unordered_map<int,int>> cache(coins.size());
        int ans = dfs(coins, 0, amount, cache);
        return ans == INT_MAX ? -1 : ans;
    }

    int dfs(const vector<int>& coins, int index, int amount,
            vector<unordered_map<int,int>>& cache) {

        if (amount == 0) return 0;

        if (index == coins.size()) return INT_MAX;

        if (cache[index].find(amount) != cache[index].end()) {
            return cache[index][amount];
        }

        int ifNotPicked = dfs(coins, index + 1, amount, cache);

        int ifPicked = INT_MAX;

        if (coins[index] <= amount) {
            int next = dfs(coins, index, amount - coins[index], cache);

            if (next != INT_MAX)
                ifPicked = 1 + next;
        }

        cache[index][amount] = min(ifNotPicked, ifPicked);

        return cache[index][amount];
    }
};
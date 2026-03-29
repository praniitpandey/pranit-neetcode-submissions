class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<unordered_map<int,int>> cache(coins.size());
        int ans = dfs(coins, 0, amount, cache);
        return (ans >= 1e9) ? -1 : ans;
    }

    int dfs(const vector<int>& coins, int index, int amount, vector<unordered_map<int,int>>& cache) {

        if (amount == 0) {
            return 0;
        }

        if (index == coins.size()) {
            return 1e9;
        }

        if (cache[index].find(amount) != cache[index].end()) {
            return cache[index][amount];
        }

        int ifNotPicked = dfs(coins, index + 1, amount, cache);
        int ifPicked = 1e9;

        if (coins[index] <= amount) {
            int res = dfs(coins, index, amount - coins[index], cache);
            if (res < 1e9) {
                ifPicked = 1 + res;
            }
        }

        cache[index][amount] = min(ifNotPicked, ifPicked);

        return cache[index][amount];
    }
};
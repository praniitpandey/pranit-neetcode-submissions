class Solution {
    public int coinChange(int[] coins, int amount) {
        Map<Integer, Integer> dp = new HashMap<>();
        int ans = dfs(coins, amount, 0, dp);
        return ans >= (int)1e9 ? -1 : ans;
    }

    private int dfs(int[] coins, int amount, int index, Map<Integer, Integer> dp) {
        if (amount == 0) {
            return 0;
        }
        if (index == coins.length) {
            return (int)1e9;
        }
        if (dp.containsKey(amount)) {
            dp.get(amount);
        }

        int ifPicked = (int)1e9, ifNotPicked = dfs(coins, amount, index + 1, dp);
        if (coins[index] <= amount) {
            ifPicked = 1 + dfs(coins, amount - coins[index], index, dp);
        }

        dp.put(amount, Math.min(ifPicked, ifNotPicked));
        return dp.get(amount);
    }
}

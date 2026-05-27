class Solution {
    public int change(int amount, int[] coins) {
        Map<String, Integer> dp = new HashMap<>();
        return dfs(coins, amount, 0, dp);
    }

    private int dfs(int[] coins, int amount, int index, Map<String, Integer> dp) {
        if (amount == 0) {
            return 1;
        }
        if (index == coins.length) {
            return 0;
        }

        String key = amount + "," + index;
        if (dp.containsKey(key)) {
            return dp.get(key);
        }

        int ifPicked = 0, ifNotPicked = dfs(coins, amount, index + 1, dp);

        if (coins[index] <= amount) {
            ifPicked = dfs(coins, amount - coins[index], index, dp);
        }

        dp.put(key, (ifPicked + ifNotPicked));
        return dp.get(key);
    }
}

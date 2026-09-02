class Solution {
    public int maxProfit(int[] prices) {
        int[][] dp = new int[prices.length][3];
        for (int[] row : dp) Arrays.fill(row, Integer.MAX_VALUE);

        return solve(prices, 0, true, false, dp);   //we start at day 0, with no stock in hand
    }

    private int solve(int[] prices, int index, boolean canBuy, boolean canSell, int[][] dp) {
        if (index == prices.length) {
            return 0;   //end of days
        }

        int key = !canBuy && !canSell ? 0 : canBuy && !canSell ? 1 : 2;
        if (dp[index][key] != Integer.MAX_VALUE) {
            return dp[index][key];
        }


        if (canBuy == false && canSell == false) {  //we're in cooldown
            int cooldownProfit = solve(prices, index + 1, true, false, dp); //can't do shit
            return dp[index][key] = cooldownProfit;
        }

        if (canBuy == true && canSell == false) {   //we're eligible to buy as we're not holding
            int buyProfit = solve(prices, index + 1, false, true, dp) - prices[index];  //what would be profit if we bought
            int waitProfit = solve(prices, index + 1, true, false, dp); //what would be profit if we didn't do shit
            
            return dp[index][key] = Math.max(buyProfit, waitProfit); //explore both options, and choose the best
        }

        if (canBuy == false && canSell == true) {   //we're eligible to sell as we're holding
            int sellProfit = solve(prices, index + 1, false, false, dp) + prices[index];   //what would be profit if we sold now (leads to cooldown)
            int holdProfit = solve(prices, index + 1, false, true, dp);   //what would be profit if we kept holding

            return dp[index][key] = Math.max(sellProfit, holdProfit); //explore both options, and choose the best
        }

        return 666; //to avoid compiler warnings
    }
}

class Solution {
    public int maxProfit(int[] prices) {
        int lowestPriceSoFar = Integer.MAX_VALUE, maxProfit = 0;

        for (int price : prices) {
            lowestPriceSoFar = Math.min(lowestPriceSoFar, price);
            maxProfit = Math.max(maxProfit, price - lowestPriceSoFar);
        }
        return maxProfit;
    }
}

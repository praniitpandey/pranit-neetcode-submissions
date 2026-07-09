class Solution {
    public int maxProfit(int[] prices) {
        int lowestPriceSoFar = Integer.MAX_VALUE;
        int maxProfitSoFar = 0;
        int maxProfitOverall = 0;

        for (int price : prices) {
            lowestPriceSoFar = Math.min(price, lowestPriceSoFar);
            maxProfitSoFar = Math.max(0, price - lowestPriceSoFar);
            maxProfitOverall = Math.max(maxProfitSoFar, maxProfitOverall);
        }

        return maxProfitOverall;
    }
}

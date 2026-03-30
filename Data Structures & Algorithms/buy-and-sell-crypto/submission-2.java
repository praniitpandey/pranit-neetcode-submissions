class Solution {
    public int maxProfit(int[] prices) {
        int lowestPriceSoFar = Integer.MAX_VALUE, maxProfitSoFar = 0, maxProfitOverall = 0;

        for (int price : prices) {
            lowestPriceSoFar = Math.min(lowestPriceSoFar, price);
            maxProfitSoFar = Math.max(maxProfitSoFar, price - lowestPriceSoFar);
            maxProfitOverall = Math.max(maxProfitOverall, maxProfitSoFar);
        }

        return maxProfitOverall;        
    }
}

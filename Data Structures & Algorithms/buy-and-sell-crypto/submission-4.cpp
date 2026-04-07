class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return helper(prices, 0, prices.size() - 1);
    }

    int helper(vector<int>& prices, int start, int end) {
        int maxProfit = 0, lowestPrice = 1e9;
        for (int i = start; i <= end; i++) {
            int currentPrice = prices[i];
            maxProfit = max(currentPrice - lowestPrice, maxProfit);
            lowestPrice = min(currentPrice, lowestPrice);
        }
        return maxProfit;
    }
};

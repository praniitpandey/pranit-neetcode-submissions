class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, lowestPrice = 1e9;
        for (auto currentPrice : prices) {
            maxProfit = max(currentPrice - lowestPrice, maxProfit);
            lowestPrice = min(currentPrice, lowestPrice);
        }
        return maxProfit;
    }
};

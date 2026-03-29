class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int last_buy_date = 0;
        int current_profit = 0;
        int total_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[i - 1]) {
                total_profit += current_profit;
                current_profit = 0;
                last_buy_date = i;
            }
            else {
                current_profit = prices[i] - prices[last_buy_date];
            }
        }

        return total_profit + current_profit;        
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int lowest_price_so_far = prices[0];
        int max_profit_at_i = 0;
        int max_profit_overall = 0;
        for (int i = 1; i < prices.size(); i++) {

            lowest_price_so_far = min(lowest_price_so_far, prices[i]);
            max_profit_at_i = max(max_profit_at_i, prices[i] - lowest_price_so_far);
            max_profit_overall = max(max_profit_overall, max_profit_at_i);

            // cout << "at i = " << i << "\n";
            // cout << "lpsf : " << lowest_price_so_far << " mpai : " << max_profit_at_i << " mpo : " << max_profit_overall << "\n";
        }
        
        return max_profit_overall;
    }
};

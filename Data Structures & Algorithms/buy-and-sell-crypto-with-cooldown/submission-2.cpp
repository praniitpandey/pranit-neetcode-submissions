class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return dfs(0, true, prices);
    }

    int dfs(int index, bool canBuy, vector<int>& prices) {
        if (index >= prices.size()) {
            return 0;
        }

        int buyProfit = INT_MIN, sellProfit = INT_MIN, holdProfit = dfs(index + 1, canBuy, prices);

        if (canBuy) {
            buyProfit = dfs(index + 1, false, prices) - prices[index];
        }
        else {
            sellProfit = dfs(index + 2, true, prices) + prices[index];
        }

        return max({buyProfit, sellProfit, holdProfit});
    }
};

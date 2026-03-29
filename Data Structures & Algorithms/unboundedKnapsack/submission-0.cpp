class Solution {
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        return dfs(profit, weight, 0, capacity);
    }
    int dfs(const vector<int>& profit, const vector<int>& weight, int index, int capacity) {
        if (index == profit.size()) {
            return 0;
        }
        int ifNotPicked = dfs(profit, weight, index + 1, capacity);
        int ifPicked = INT_MIN;

        if (weight[index] <= capacity) {
            ifPicked = profit[index] + dfs(profit, weight, index, capacity - weight[index]);
        }

        return max(ifNotPicked, ifPicked);
    }

};

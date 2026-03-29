class Solution {
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        return dfs(profit, weight, capacity, 0);        
    }
    int dfs(vector<int>& profit, vector<int>& weight, int capacity, int index) {
        if (index >= weight.size() || capacity == 0) {
            return 0;
        }
        else if (weight[index] > capacity) {
            return dfs(profit, weight, capacity, ++index);
        }
        else {
            int ifPicked = profit[index] + dfs(profit, weight, capacity - weight[index], index + 1);
            int ifNotPicked = dfs(profit, weight, capacity, index + 1);

            return max(ifPicked, ifNotPicked);
        }
    }
};

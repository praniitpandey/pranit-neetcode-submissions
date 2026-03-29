class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int min_cost_at_i_2 = cost[0], min_cost_at_i_1 = cost[1], min_cost_at_i;

        if (cost.size() == 2) {
            return min(cost[0], cost[1]);
        }

        for (int i = 2; i < cost.size(); i++) {
            min_cost_at_i = cost[i] + min(min_cost_at_i_1, min_cost_at_i_2);
            min_cost_at_i_2 = min_cost_at_i_1;
            min_cost_at_i_1 = min_cost_at_i;
        }

        return min(min_cost_at_i_1, min_cost_at_i_2);
    }
};
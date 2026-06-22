class Solution {
    unordered_map<string, int> dp;
public:
    int numSquares(int n) {
        int root = sqrt(n);
        return dfs(root, n);        
    }

private:
    int dfs(int num, int target) {
        if (target == 0) {
            return 0;
        }
        if (num <= 0) {
            return 1e9;
        }
        string key = to_string(num) + "," + to_string(target);
        if (dp.count(key)) {
            return dp[key];
        }

        int ifNotPicked = dfs(num - 1, target);
        int ifPicked = 1e9;

        if (num * num <= target) {
            ifPicked = 1 + dfs(num, target - (num * num));
        }

        return dp[key] = min(ifPicked, ifNotPicked);
    }
};
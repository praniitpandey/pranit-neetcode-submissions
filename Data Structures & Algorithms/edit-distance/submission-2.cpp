class Solution {
public:
    int minDistance(string word1, string word2) {
        dp.assign(word1.size(), vector<int>(word2.size(), -1));
        return solve(word1, word2, 0, 0);
    }

private:
    vector<vector<int>> dp;
    int solve(string word1, string word2, int i, int j) {
        if (i == word1.size() || j == word2.size())
            return max((word1.size() - i), (word2.size() - j));

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = solve(word1, word2, i + 1, j + 1);

        int insertCost = 1 + solve(word1, word2, i + 1, j);
        int deleteCost = 1 + solve(word1, word2, i, j + 1);
        int replaceCost = 1 + solve(word1, word2, i + 1, j + 1);

        return dp[i][j] = min({insertCost, deleteCost, replaceCost});
    }
};
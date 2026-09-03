class Solution {
public:
    bool isMatch(string s, string p) {
        dp.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dfs(s, p, 0, 0);
    }
private:
    vector<vector<int>> dp;

    bool dfs(string s, string p, int i, int j) {
        if (j == p.size())
            return i == s.size();

        if (dp[i][j] != -1)
            return dp[i][j];

        bool match = i < s.size() && (s[i] == p[j] || p[j] == '.'), ans;

        if (j < p.size() - 1 && p[j + 1] == '*')
            ans = dfs(s, p, i, j + 2) || (match && dfs(s, p, i + 1, j));
        else if (match)
            ans = dfs(s, p, i + 1, j + 1);

        return dp[i][j] = ans;
    }
};

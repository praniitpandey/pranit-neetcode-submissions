class Solution {
public:
    bool isMatch(string s, string p) {
        dp.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dfs(s, p, 0, 0);
    }
private:
    vector<vector<int>> dp;

    bool dfs(const string& s, const string& p, int i, int j) {
        if (j == p.size()) {
            return i == s.size();
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool first_match = (i < s.size() && (p[j] == s[i] || p[j] == '.'));

        bool res;
        if (j + 1 < p.size() && p[j + 1] == '*') {
            res = dfs(s, p, i, j + 2) || (first_match && dfs(s, p, i + 1, j));
        } else {
            res = first_match && dfs(s, p, i + 1, j + 1);
        }

        return dp[i][j] = res;
    }
};
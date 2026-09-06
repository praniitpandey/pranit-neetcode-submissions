class Solution {
public:
    bool isMatch(string s, string p) {
        dp.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(s, p, 0, 0);        
    }

private:
    vector<vector<int>> dp;

    bool solve(string s, string p, int i, int j) {
        if (j == p.size())
            return (i == s.size());

        if (dp[i][j] != -1)
            return dp[i][j];

        bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');
        bool ans;
        if (j < p.size() - 1 && p[j + 1] == '*')
            ans = solve(s, p, i, j + 2) || match && solve(s, p, i + 1, j);
        else
            ans = match && solve(s, p, i + 1, j + 1);

        return dp[i][j] = ans;
    }
};

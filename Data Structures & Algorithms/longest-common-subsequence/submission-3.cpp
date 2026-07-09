class Solution {
private:
    unordered_map<string, int> dp;
    int dfs(const string& text1, const string& text2, int i, int j) {
        if (i == text1.size() || j == text2.size()) {
            return 0;
        }

        string key = to_string(i) + "," + to_string(j);

        if (dp.count(key)) {
            return dp[key];
        }

        if (text1[i] == text2[j]) {
            return dp[key] = 1 + dfs(text1, text2, i + 1, j + 1);
        }
        else {
            return dp[key] = max(dfs(text1, text2, i + 1, j), dfs(text1, text2, i, j + 1));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        return dfs(text1, text2, 0, 0);        
    }
};

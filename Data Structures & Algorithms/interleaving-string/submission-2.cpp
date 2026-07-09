class Solution {
private:
    unordered_map<string, bool> dp;

    bool dfs(string s1, string s2, string s3, int i, int j) {
        int k = i + j;

        if (k == s3.size())
            return true;

        string key = to_string(i) + "," + to_string(j);
        if (dp.count(key))
            return dp[key];

        bool ifs1 = false, ifs2 = false;

        if (i < s1.size() && s1[i] == s3[k])
            ifs1 = dfs(s1, s2, s3, i + 1, j);
        
        if (j < s2.size() && s2[j] == s3[k])
            ifs2 = dfs(s1, s2, s3, i, j + 1);

        return dp[key] = (ifs1 || ifs2);
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        return dfs(s1, s2, s3, 0, 0);
    }
};

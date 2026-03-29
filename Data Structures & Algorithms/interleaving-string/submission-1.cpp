class Solution {
private:
    vector<vector<int>> cache;
    bool dfs(int i, int j, string& s1, string& s2, string& s3) {
        int k = i + j;
        if (k == s3.length()) {
            return (i == s1.length()) && (j == s2.length());
        }
        if (cache[i][j] != -1) {
            return cache[i][j] == 1;
        }

        if (i < s1.length() && s1[i] == s3[k]) {
            if (dfs(i + 1, j, s1, s2, s3)) {
                cache[i][j] = 1;
                return true;
            }
        }

        if (j < s2.length() && s2[j] == s3[k]) {
            if (dfs(i, j + 1, s1, s2, s3)) {
                cache[i][j] = 1;
                return true;
            }
        }

        cache[i][j] = 0;
        return false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        
        cache = vector<vector<int>> (s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return dfs(0, 0, s1, s2, s3);
    }
};
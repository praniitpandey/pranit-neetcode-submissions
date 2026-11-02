class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ROWS = matrix.size();
        COLS = matrix[0].size();
        dp.resize(ROWS, vector<int>(COLS, -1));

        int ans = 1;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                ans = max(ans, dfs(matrix, r, c));
            }
        }

        return ans;        
    }

private:
    int ROWS;
    int COLS;
    vector<vector<int>> dp;

    int dfs(const vector<vector<int>>& matrix, int r, int c) {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS)
            return 0;

        if (dp[r][c] != -1)
            return dp[r][c];

        dp[r][c] = 1;

        int nr, nc;
        int dirs[] = {0, 1, 0, -1, 0};
        for (int i = 0; i <= 3; i++) {
            nr = r + dirs[i];
            nc = c + dirs[i + 1];

            if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || matrix[nr][nc] >= matrix[r][c])
                continue;

            dp[r][c] = max(dp[r][c], 1 + dfs(matrix, nr, nc));
        }

        return dp[r][c];
    }
};

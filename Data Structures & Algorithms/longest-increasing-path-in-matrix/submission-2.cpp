class Solution {
private:
    int ROWS;
    int COLS;
    vector<vector<int>> dp;

    int dfs(const vector<vector<int>>& matrix, int r, int c) {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
            return 0;
        }

        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        int longestPathHere = 1;
        int dirs[] = {0, 1, 0, -1, 0};

        for (int i = 1; i < 5; i++) {
            int nr = r + dirs[i - 1];
            int nc = c + dirs[i];

            if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS)
                continue;

            if (matrix[nr][nc] > matrix[r][c])
                longestPathHere = max(longestPathHere, 1 + dfs(matrix, nr, nc));
        }

        return dp[r][c] = longestPathHere;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ROWS = matrix.size();
        COLS = matrix[0].size();
        dp.assign(ROWS, vector<int>(COLS, -1));

        int longestPathHere, longestPathOverall = 1;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                longestPathHere = dfs(matrix, r, c);
                longestPathOverall = max(longestPathHere, longestPathOverall);
            }
        }

        return longestPathOverall;
    }
};
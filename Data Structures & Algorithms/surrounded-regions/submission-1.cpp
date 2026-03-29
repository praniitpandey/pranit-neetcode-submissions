class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 'O') {
                dfs(grid, i, 0);
            }
            if (grid[i][n - 1] == 'O') {
                dfs(grid, i, n - 1);
            }
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 'O') {
                dfs(grid, 0, j);
            }
            if (grid[m - 1][j] == 'O') {
                dfs(grid, m - 1, j);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'O') {
                    grid[i][j] = 'X';
                }
                if (grid[i][j] == '+') {
                    grid[i][j] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '+' || grid[i][j] == 'X') {
            return;
        }

        grid[i][j] = '+';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};
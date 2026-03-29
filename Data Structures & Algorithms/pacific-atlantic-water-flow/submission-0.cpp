class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(grid, i, 0, pacific);
            dfs(grid, i, n - 1, atlantic);
        }
        for (int j = 0; j < n; j++) {
            dfs(grid, 0, j, pacific);
            dfs(grid, m - 1, j, atlantic);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;        
    }

    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) {
            return;
        }

        visited[i][j] = true;

        if (i > 0 && grid[i][j] <= grid[i - 1][j]) {
            dfs(grid, i - 1, j, visited);
        }
        if (i < m - 1 && grid[i][j] <= grid[i + 1][j]) {
            dfs(grid, i + 1, j, visited);
        }
        if (j > 0 && grid[i][j] <= grid[i][j - 1]) {
            dfs(grid, i, j - 1, visited);
        }
        if (j < n - 1 && grid[i][j] <= grid[i][j + 1]) {
            dfs(grid, i, j + 1, visited);
        }
    }
};

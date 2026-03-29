class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), name = 2;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, name++);
                }
            }
        }

        vector<int> areas(m * n, 0);
        int maxArea = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 1) {
                    ++areas[grid[i][j]];
                    maxArea = max(areas[grid[i][j]], maxArea);
                }
            }
        }

        return maxArea;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int name) {
        int m = grid.size(), n = grid[0].size();
        if (i >= m || j >= n || i < 0 || j < 0 || grid[i][j] != 1) {
            return;
        }

        grid[i][j] = name;
        dfs(grid, i + 1, j, name);
        dfs(grid, i - 1, j, name);
        dfs(grid, i, j + 1, name);
        dfs(grid, i, j - 1, name);
    } 
};

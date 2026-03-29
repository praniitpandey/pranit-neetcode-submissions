class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) {
            return 0;
        }

        vector<vector<int>> paths(m, vector<int>(n, 0));
        paths[0][0] = 1;

        for (int i = 1; i < m; i++) {
            paths[i][0] = (grid[i][0] == 1) ? 0 : paths[i - 1][0];
        }

        for (int j = 1; j < n; j++) {
            paths[0][j] = (grid[0][j] == 1) ? 0 : paths[0][j - 1];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                paths[i][j] = (grid[i][j] == 1) ? 0 : paths[i - 1][j] + paths[i][j - 1];
            }
        }
        
        return paths[m - 1][n - 1];
    }
};
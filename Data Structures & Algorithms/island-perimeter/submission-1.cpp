class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int perimeter = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int up = 0, down = 0, right = 0, left = 0;

                    if ((i == 0) || ((i > 0) && (grid[i - 1][j] == 0))) {
                        left = 1;
                    }
                    if ((i == m - 1) || ((i < m - 1) && (grid[i + 1][j] == 0))) {
                        right = 1;
                    }
                    if ((j == 0) || ((j > 0) && (grid[i][j - 1] == 0))) {
                        up = 1;
                    }
                    if ((j == n - 1) || ((j < n - 1) && (grid[i][j + 1] == 0))) {
                        down = 1;
                    }

                    perimeter += (up + down + left + right);
                }
            }
        }

        return perimeter;
    }
};
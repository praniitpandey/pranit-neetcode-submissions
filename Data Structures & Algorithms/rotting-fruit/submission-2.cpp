class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int fresh = 0;
        queue<pair<int, int>> bfs;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    ++fresh;
                }
                else if (grid[r][c] == 2) {
                    bfs.push({r, c});
                }
            }
        }

        int time = 0;
        while (!bfs.empty() && fresh > 0) {
            int size = bfs.size();
            ++time;

            for (int i = 0; i < size; i++) {
                auto [r , c] = bfs.front();
                bfs.pop();

                if (r > 0 && grid[r - 1][c] == 1) {
                    grid[r - 1][c] = 2;
                    bfs.push({r - 1, c});

                    --fresh;
                }
                if (r < (m - 1) && grid[r + 1][c] == 1) {
                    grid[r + 1][c] = 2;
                    bfs.push({r + 1, c});

                    --fresh;
                }
                if (c > 0 && grid[r][c - 1] == 1) {
                    grid[r][c - 1] = 2;
                    bfs.push({r, c - 1});

                    --fresh;
                }
                if (c < (n - 1) && grid[r][c + 1] == 1) {
                    grid[r][c + 1] = 2;
                    bfs.push({r, c + 1});

                    --fresh;
                }
            }
        }

        if (fresh == 0) {
            return time;
        }
        else {
            return -1;
        }
    }
};
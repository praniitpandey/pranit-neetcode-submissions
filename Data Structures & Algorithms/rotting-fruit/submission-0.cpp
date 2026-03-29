class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> time(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> bfs;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    time[i][j] = 0;
                    bfs.push({i, j});
                }
                else if (grid[i][j] == 0) {
                    time[i][j] = -1;
                }
            }
        }

        while (!bfs.empty()) {
            pair<int, int> curr = bfs.front();
            bfs.pop();

            int i = curr.first;
            int j = curr.second;

            if (i < m - 1) {
                if (time[i + 1][j] == INT_MAX) {
                    time[i + 1][j] = time[i][j] + 1;
                    bfs.push({i + 1, j});
                }
            }
            if (i > 0) {
                if (time[i - 1][j] == INT_MAX) {
                    time[i - 1][j] = time[i][j] + 1;
                    bfs.push({i - 1, j});
                }
            }
            if (j < n - 1) {
                if (time[i][j + 1] == INT_MAX) {
                    time[i][j + 1] = time[i][j] + 1;
                    bfs.push({i, j + 1});
                }
            }
            if (j > 0) {
                if (time[i][j - 1] == INT_MAX) {
                    time[i][j - 1] = time[i][j] + 1;
                    bfs.push({i, j - 1});
                }
            }

        }

        int minTime = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (time[i][j] == INT_MAX) {
                    return -1;
                }
                if (time[i][j] > -1) {
                    minTime = max(minTime, time[i][j]);
                }
            }
        }
        

        return minTime;
    }
};

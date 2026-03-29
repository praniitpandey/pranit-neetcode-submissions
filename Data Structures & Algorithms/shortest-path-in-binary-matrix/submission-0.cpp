class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size();
        int direct[10] = {0, 1, 0, -1, 0, 1, 1, -1, -1, 1};

        if (grid[0][0] || grid[N - 1][N - 1])
            return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            int dist = grid[r][c];

            if (r == N - 1 && c == N - 1)
                return dist;

            for (int d = 0; d < 9; d++) {
                int nr = r + direct[d], nc = c + direct[d + 1];

                if (nr >= 0 && nc >= 0 && nr < N && nc < N && grid[nr][nc] == 0) {
                    grid[nr][nc] = dist + 1;
                    q.push({nr, nc});
                }
            }
        }

        return -1;
    }
};
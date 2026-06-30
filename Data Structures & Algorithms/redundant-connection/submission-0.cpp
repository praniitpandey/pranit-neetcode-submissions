class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adj = vector<vector<int>>(n + 1, vector<int>());
        vector<int> degree(n + 1, 0);

        for (auto& edge : edges) {
            int v = edge[0], u = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            ++degree[u];
            ++degree[v];
        }

        queue<int> bfs;
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 1) {
                bfs.push(i);
            }
        }

        while (!bfs.empty()) {
            int u = bfs.front();
            bfs.pop();
            degree[u] = 0;

            for (int v : adj[u]) {
                if (degree[v] > 1) {
                    --degree[v];
                    if (degree[v] == 1) {
                        bfs.push(v);
                    }
                }
            }
        }

        for (int i = edges.size() - 1; i >= 0; i--) {
            int u = edges[i][0], v = edges[i][1];

            if (degree[u] > 0 && degree[v] > 0) {
                return {u, v};
            }
        }

        return {-1, -1};
    }
};
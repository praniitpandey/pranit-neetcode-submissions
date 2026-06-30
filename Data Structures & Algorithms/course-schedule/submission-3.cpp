class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj = vector<vector<int>>(n, vector<int>());
        vector<int> indegree(n, 0);

        for (auto& edge : edges) {
            int v = edge[0], u = edge[1];
            adj[u].push_back(v);
            ++indegree[v];
        }

        queue<int> bfs;
        for (int u = 0; u < n; u++) {
            if (indegree[u] == 0) {
                bfs.push(u);
            }
        }

        int count = 0;
        while (!bfs.empty()) {
            int u = bfs.front();
            bfs.pop();
            ++count;

            for (int v : adj[u]) {
                --indegree[v];

                if (indegree[v] == 0) {
                    bfs.push(v);
                }
            }
        }

        return count == n;
    }
};
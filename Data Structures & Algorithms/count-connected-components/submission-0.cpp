class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        vector<bool> visited(n, false);

        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ++count;
                visited[i] = true;

                queue<int> bfs;
                bfs.push(i);

                while (!bfs.empty()) {
                    int u = bfs.front();
                    bfs.pop();

                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            bfs.push(v);
                        }
                    }
                }
            }
        }

        return count;
    }
};

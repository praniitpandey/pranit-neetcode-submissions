class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> adj(n + 1, vector<int>());
        vector<int> indegree(n + 1, 0);

        for (auto& edge : relations) {
            adj[edge[0]].push_back(edge[1]);
            ++indegree[edge[1]];
        }

        queue<int> bfs;
        for (int u = 1; u <= n; u++) {
            if (indegree[u] == 0) {
                bfs.push(u);
            }
        }

        int semesters = 0;
        int count = 0;
        while (!bfs.empty()) {
            int size = bfs.size();
            semesters++;
            for (int i = 0; i < size; i++) {
                int u = bfs.front();
                bfs.pop();
                count++;

                for (int v : adj[u]) {
                    --indegree[v];

                    if (indegree[v] == 0) {
                        bfs.push(v);
                    }
                }
            }
        }

        return count == n ? semesters : -1;
    }
};
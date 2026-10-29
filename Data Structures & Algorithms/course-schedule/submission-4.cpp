class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int> indegree(n, 0);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            ++indegree[edge[1]];
        }

        queue<int> bfs;
        for (int v = 0; v < n; v++)
            if (indegree[v] == 0)
                bfs.push(v);

        int count = 0;
        while (!bfs.empty()) {
            int u = bfs.front();
            bfs.pop();
            ++count;

            for (int v : adj[u]) {
                --indegree[v];

                if (indegree[v] == 0)
                    bfs.push(v);
            }
        }

        return (count == n);
    }
};

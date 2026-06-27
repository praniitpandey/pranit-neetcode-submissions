class Solution {
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<bool> visiting;
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        adj = vector<vector<int>>(n, vector<int>());
        visited = vector<bool>(n, false);
        visiting = vector<bool>(n, false);

        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < n; i++) {
            if (hasCycle(i)) {
                return false;
            }
        }

        return true;
    }

private:
    bool hasCycle(int u) {
        if (visited[u]) {
            return false;
        }
        if(visiting[u]) {
            return true;
        }

        visiting[u] = true;

        for (auto v : adj[u]) {
            if (hasCycle(v)) {
                return true;
            }
        }

        visiting[u] = false;
        visited[u] = true;
        
        return false;
    }
};
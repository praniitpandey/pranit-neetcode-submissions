class Solution {
    vector<vector<int>> adj;
    vector<int> state;
    // state 0 : unexplored
    // state 1 : node in current path
    // state 2 : node totally explored
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        adj = vector<vector<int>>(n, vector<int>());
        state = vector<int>(n, 0);

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
        if (state[u] == 2) {
            return false;    //already explored, no need to check
        }
        if (state[u] == 1) {
            return true;    //cycle detected
        }

        state[u] = 1;
        for (int v : adj[u]) {
            if (hasCycle(v)) {
                return true;
            }
        }
        state[u] = 2;

        return false;
    }
};
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);

        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        queue<int> bfs;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                bfs.push(i);
            }
        }

        vector<int> order;
        while (!bfs.empty()) {
            int u = bfs.front();
            bfs.pop();

            order.push_back(u);

            for (int v : adj[u]) {
                --indegree[v];

                if (indegree[v] == 0) {
                    bfs.push(v);
                }
            }
        }

        return order.size() == numCourses ? order : vector<int>();
    }
};

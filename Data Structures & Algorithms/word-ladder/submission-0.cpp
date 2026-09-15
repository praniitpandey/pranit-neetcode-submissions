class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& words) {
        if (begin == end)
            return 0;
        words.push_back(begin);

        int n = words.size();
        unordered_map<string, vector<string>> adj;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int mismatches = 0;

                for (int k = 0; k < words[i].size(); k++) {
                    if (words[i][k] != words[j][k]) {
                        ++mismatches;
                    }

                    if (mismatches > 1) {
                        break;
                    }
                }

                if (mismatches == 1) {
                    adj[words[i]].push_back(words[j]);
                    adj[words[j]].push_back(words[i]);
                }
            }
        }

        unordered_map<string, bool> visited;
        queue<string> bfs;
        bfs.push(begin);
        visited[begin] = true;
        int steps = 1;

        while (!bfs.empty()) {
            int size = bfs.size();

            for (int i = 0; i < size; i++) {
                string current = bfs.front();
                bfs.pop();

                for (string next : adj[current]) {
                    if (next == end)
                        return steps + 1;

                    else if (!visited[next]) {
                        visited[next] = true;
                        bfs.push(next);
                    }
                }
            }

            ++steps;
        }

        return 0;
    }
};

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<unordered_set<string>> lengths(1001);
        int minLength = 1001;
        for (string word : words) {
            lengths[(int)word.size()].insert(word);
            minLength = min(minLength, (int)word.size());
        }
        
        unordered_map<string, vector<string>> adj;
        for (int l = minLength; l < 1000; l++) {
            for (const string& s : lengths[l]) {
                for (const string& p : lengths[l + 1]) {
                    int i = 0, j = 0;
                    while (i < s.size() && j < p.size()) {
                        if (s[i] == p[j])
                            ++i;
                        ++j;
                    }

                    if (i == s.size()) {
                        adj[s].push_back(p);
                    }
                }
            }
        }

        queue<pair<string, int>> bfs;
        for (int l = minLength; l <= 1000; l++) {
            for (const string& u : lengths[l]) {
                bfs.push(make_pair(u, 1));
            }
        }

        int maxChain = 1;
        while (!bfs.empty()) {
            auto [u, chain] = bfs.front();
            bfs.pop();

            for (const string& v : adj[u])
                bfs.push(make_pair(v, chain + 1));

            maxChain = max(chain, maxChain);
        }

        return maxChain;
    }
};
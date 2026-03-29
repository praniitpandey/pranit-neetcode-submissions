class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visit(deadends.begin(), deadends.end());
        if (visit.find("0000") != visit.end()) {
            return -1;
        }

        queue<pair<int, string>> bfs;
        bfs.push(make_pair(0, "0000"));
        visit.insert("0000");

        while (!bfs.empty()) {
            auto [distance, state] = bfs.front();
            bfs.pop();
            for (int i = 0; i < 4; i++) {
                string newState1 = state;
                newState1[i] = state[i] == '9' ? '0' : state[i] + 1;

                if (newState1 == target) {
                    return distance + 1;
                }
                else if (visit.find(newState1) == visit.end()) {
                    bfs.push(make_pair(distance + 1, newState1));
                    visit.insert(newState1);
                }

                string newState2 = state;
                newState2[i] = state[i] == '0' ? '9' : state[i] - 1;

                if (newState2 == target) {
                    return distance + 1;
                }
                else if (visit.find(newState2) == visit.end()) {
                    bfs.push(make_pair(distance + 1, newState2));
                    visit.insert(newState2);
                }
            }
        }

        return -1;
    }
};
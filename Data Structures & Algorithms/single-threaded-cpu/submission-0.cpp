class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& task) {
        int n = task.size();
        for (int i = 0; i < n; i++) {
            task[i].push_back(i);
        }
        sort(task.begin(), task.end());

        auto cmp = [](pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        vector<int> order;
        long long time = task[0][0];
        int i = 0;

        while (i < n || !pq.empty()) {

            while (i < n && time >= task[i][0]) {
                pq.push({task[i][1], task[i][2]});
                ++i;
            }
            if (i < n && pq.empty()) {
                time = task[i][0];
            }
            else {
                pair<int, int> currentTask = pq.top();
                pq.pop();
                time += currentTask.first;
                order.push_back(currentTask.second);
            }
        }
        return order;        
    }
};
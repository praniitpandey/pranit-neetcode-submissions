class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i = 0; i < n; i++) {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());

        auto cmp = [](pair<int, int> a, pair<int, int> b) {
            return a.first > b.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);

        int i = 0;
        long long time = tasks[i][0];
        vector<int> answer;

        while (i < n || !minHeap.empty()) {
            while (i < n && time >= tasks[i][0]) {
                minHeap.push(make_pair(tasks[i][1], tasks[i][2]));
                i++;
            }
            if (minHeap.empty()) {
                minHeap.push(make_pair(tasks[i][1], tasks[i][2]));
                time = tasks[i][0];
                i++;
            }
            else {
                auto [processingTime, taskIndex] = minHeap.top();
                minHeap.pop();

                time += processingTime;
                answer.push_back(taskIndex);
            }
        }

        return answer;        
    }
};
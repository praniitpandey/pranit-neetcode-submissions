class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) {

        vector<pair<int, int>> projects;
        int n = profit.size();
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profit[i]});
        }
        sort(projects.begin(), projects.end());

        priority_queue<int> pq;
        int idx = 0;
        for (int i = 0; i < k; i++) {
            while (idx < n && projects[idx].first <= w) {
                pq.push(projects[idx].second);
                idx++;
            }

            if (pq.empty()) break;

            w += pq.top();
            pq.pop();
        }
        
        return w;
    }
};
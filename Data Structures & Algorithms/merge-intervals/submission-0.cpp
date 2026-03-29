class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> solution;
        vector<int> currentInterval;
        for (int i = 0; i < intervals.size(); i++) {
            currentInterval = intervals[i];

            while ((i < intervals.size()) && (currentInterval[1] >= intervals[i][0])) {
                currentInterval[0] = min(currentInterval[0], intervals[i][0]);
                currentInterval[1] = max(currentInterval[1], intervals[i][1]);
                i++;
            }

            i--;

            solution.push_back(currentInterval);
        }
        return solution;
    }
};
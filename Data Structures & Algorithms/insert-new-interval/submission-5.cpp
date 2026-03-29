class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> solution;
        int i = 0;

        while ((i < intervals.size()) && (intervals[i][1] < newInterval[0])) {
            solution.push_back(intervals[i++]);
        }

        while ((i < intervals.size()) && (newInterval[1] >= intervals[i][0])) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        solution.push_back(newInterval);

        while (i < intervals.size()) {
            solution.push_back(intervals[i++]);
        }

        return solution;        
    }
};

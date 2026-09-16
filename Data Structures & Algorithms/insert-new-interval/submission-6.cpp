class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals.front());

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= merged.back()[1])
                merged.back()[1] = max(intervals[i][1], merged.back()[1]);
            else
                merged.push_back(intervals[i]);
        }

        return merged;
    }
};

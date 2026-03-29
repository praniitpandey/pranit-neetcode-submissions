class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1], count = 0;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) {
                ++count;
                prevEnd = min(intervals[i][1], prevEnd);
            }
            else {
                prevEnd = intervals[i][1];
            }
        }
        return count;        
    }
};
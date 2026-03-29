class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        for (int i = 0; i < (int)intervals.size() - 1; i++) {
            if (intervals[i].end > intervals[i + 1].start) {
                return false;
            }        
        }

        return true;        
    }
};
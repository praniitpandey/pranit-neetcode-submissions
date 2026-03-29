class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> valid;
        vector<int> mergedInterval = newInterval;

        for (int i = 0; i < intervals.size(); i++) {
            if ((intervals[i][0] <= newInterval[0]) && (newInterval[1] <= intervals[i][1])) {
                cout << "overlap case 1" << endl;

                mergedInterval[0] = intervals[i][0];
                mergedInterval[1] = intervals[i][1];
            }
            else if ((intervals[i][0] <= mergedInterval[0]) && (mergedInterval[0] <= intervals[i][1])) {
                cout << "overlap case 2" << endl;

                mergedInterval[0] = intervals[i][0];
            }
            else if ((intervals[i][0] <= mergedInterval[1]) && (mergedInterval[1] <= intervals[i][1])) {
                cout << "overlap case 3" << endl;

                mergedInterval[1] = intervals[i][1];
            }
            else if ((mergedInterval[0] <= intervals[i][0]) && (intervals[i][1] <= mergedInterval[1])) {
                cout << "overlap case 4" << endl;
            }
            else {
                valid.push_back(intervals[i]);
            }
        }

        cout << "[" << mergedInterval[0] << "]" << "[" << mergedInterval[1] << "]";
        valid.push_back(mergedInterval);
        sort(valid.begin(), valid.end());

        return valid;    
    }
};
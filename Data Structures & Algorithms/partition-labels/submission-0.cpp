class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<vector<int>> hash(26, {s.size(), -1});
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'][0] = min(hash[s[i] - 'a'][0], i);
            hash[s[i] - 'a'][1] = max(hash[s[i] - 'a'][0], i);
        }   //calculating first and last index of each distinct character and storing in hash (array of size 26 can be used)

        vector<vector<int>> intervals;
        for (int i = 0; i < 26; i++) {
            if (hash[i][1] > -1) {
                intervals.push_back(hash[i]);
            }
        }
        sort(intervals.begin(), intervals.end()); //reformatting hash as sorted intervals

        vector<int> currentInterval;
        vector<vector<int>> mergedIntervals;
        for (int i  = 0; i < intervals.size(); i++) {
            currentInterval = intervals[i];

            while ((i < intervals.size()) && (currentInterval[1] >= intervals[i][0])) {
                currentInterval[0] = min(currentInterval[0], intervals[i][0]);
                currentInterval[1] = max(currentInterval[1], intervals[i][1]);
                i++;
            }
            i--;

            mergedIntervals.push_back(currentInterval);
        }   //merging these sorted intervals

        vector<int> mergedIntervalLengths;
        for (int i = 0; i < mergedIntervals.size(); i++) {
            mergedIntervalLengths.push_back(mergedIntervals[i][1] - mergedIntervals[i][0] + 1);
        }
 
        return mergedIntervalLengths;
    }
};

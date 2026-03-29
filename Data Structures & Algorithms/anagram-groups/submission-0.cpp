class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> solution;
        map<string, vector<string>> sorted;

        for (int i = 0; i < strs.size(); ++i) {
            string key = strs[i];
            sort(key.begin(), key.end());
            sorted[key].push_back(strs[i]);
        }

        for (auto it = sorted.begin(); it != sorted.end(); it++) {
            solution.push_back(it->second);
        }

        return solution;        
    }
};

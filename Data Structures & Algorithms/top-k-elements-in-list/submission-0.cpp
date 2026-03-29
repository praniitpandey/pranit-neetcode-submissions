class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int size = nums.size();
        unordered_map<int, int> frequency;
        for (int i = 0; i < size; i++) {
            ++frequency[nums[i]];
        }
        
        vector<vector<int>> sorted_frequency(size + 1);
        for (auto it = frequency.begin(); it != frequency.end(); it++) {
            sorted_frequency[it->second].push_back(it->first);
        }

        // for (int i = 0; i < sorted_frequency.size(); i++) {
        //     cout << "sorted_frequency[" << i << "] : { ";
        //     for (int j = 0; j < sorted_frequency[i].size(); j++) {
        //         cout << sorted_frequency[i][j] << " ";
        //     }
        //     cout << "}\n";
        // }

        int count = 0;
        vector<int> solution;
        for (int i = size; i >= 0 && count < k; i--) {
            // cout << "i : " << i << "\n";
            for (int j = 0; j < sorted_frequency[i].size(); j++) {
                solution.push_back(sorted_frequency[i][j]);
                // cout << "j : " << j << "\n";
            }
            count += sorted_frequency[i].size();
        }

        return solution;  
    }
};

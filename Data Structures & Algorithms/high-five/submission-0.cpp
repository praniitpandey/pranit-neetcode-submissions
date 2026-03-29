class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, priority_queue<int>> allScores;

        for (vector<int> item : items) {
            allScores[item[0]].push(item[1]);
        }

        vector<vector<int>> ans;
        for (auto it : allScores) {
            int student = it.first;
            priority_queue<int> score = it.second;
            int sum = 0;

            for (int i = 0; i < 5 && !score.empty(); i++) {
                sum += score.top();
                score.pop();
            }

            ans.push_back({student, sum/5});
        }
        sort(ans.begin(), ans.end());

        return ans;        
    }
};

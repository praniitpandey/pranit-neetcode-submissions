class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> solution(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (temp[j] > temp[i]) {
                    solution[i] = (j-i);
                    break;
                }
            }
        }
        
        return solution;
    }
};

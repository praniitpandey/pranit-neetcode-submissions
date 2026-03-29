class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> solution(n, 0);
        stack<pair<int, int>> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first <= temp[i]) {
                st.pop();
            }

            if (!st.empty()) {
                solution[i] = st.top().second - i;
            }      
            st.push({temp[i], i});
        }
        
        return solution;
    }
};
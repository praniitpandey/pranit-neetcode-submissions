class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> ans;

        for (int i = 1; i <= n + 1; i++) {
            ans.push_back(vector<int>(i, 1));
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }

        return ans.back();        
    }
};
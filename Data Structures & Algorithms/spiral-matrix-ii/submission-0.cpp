class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int count = 0;

        vector<vector<int>> ans(n, vector<int>(n, 0));

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                ans[top][i] = ++count;
            }
            for (int j = top + 1; j <= bottom; j++) {
                ans[j][right] = ++count;
            }
            for (int i = right - 1; i >= left; i--) {
                ans[bottom][i] = ++count;
            }
            for (int j = bottom - 1; j >= top + 1; j--) {
                ans[j][left] = ++count;
            }

            ++left;
            --right;
            ++top;
            --bottom;
        }

        return ans;        
    }
};
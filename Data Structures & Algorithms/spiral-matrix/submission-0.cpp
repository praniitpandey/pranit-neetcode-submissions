class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        vector<int> solution;
        while (left <= right && top <= bottom) {
            for (int c = left; c <= right; c++) {
                solution.push_back(matrix[top][c]);
            }

            for (int r = top + 1; r <= bottom; r++) {
                solution.push_back(matrix[r][right]);
            }

            if (top < bottom) {
                for (int c = right - 1; c >= left; c--) {
                    solution.push_back(matrix[bottom][c]);
                }
            }

            if (left < right) {
                for (int r = bottom - 1; r >= top + 1; r--) {
                    solution.push_back(matrix[r][left]);
                }
            }

            left++, right--, top++, bottom--;
        }
        
        return solution;
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        unordered_set<int> zero_rows;
        unordered_set<int> zero_cols;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    zero_rows.insert(i);
                    zero_cols.insert(j);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (zero_rows.find(i) != zero_rows.end() || zero_cols.find(j) != zero_cols.end()) {
                    matrix[i][j] = 0;
                }
            }
        }        
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = (m * n) - 1;
        int mid;

        while (i <= j) {
            mid = (i + j) / 2;

            if (target < matrix[mid/n][mid%n]) {
                j = mid - 1;
            }
            else if (target > matrix[mid/n][mid%n]) {
                i = mid + 1;
            }
            else {
                return true;
            }
        }

        return false;       
    }
};

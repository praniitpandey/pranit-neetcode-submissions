class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;

        int left = 0, right = m * n - 1, mid = 0;

        while (left <= right) {
            mid = left + (right - left)/2;

            int i = (mid / n);
            int j = (mid % n);

            if (matrix[i][j] > target) {
                right = mid - 1;
            }
            else if (matrix[i][j] < target) {
                left = mid + 1;
            }
            else {
                return true;
            }
        }
        return false;        
    }
}

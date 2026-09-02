class Solution {
    public int maximalSquare(char[][] matrix) {
        int ROWS = matrix.length, COLS = matrix[0].length, ans = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if ((r == 0 || c == 0) && matrix[r][c] == '1') {
                    ans = Math.max(ans, 1);
                }
                else if (matrix[r][c] == '1') {
                    matrix[r][c] = (char)('1' + Math.min((int)(matrix[r - 1][c - 1] - '0'), 
                        Math.min((int)(matrix[r - 1][c] - '0'), (int)(matrix[r][c - 1]) - '0')));
                    ans = Math.max(ans, (int)(matrix[r][c] - '0'));
                }
            }
        }

        return ans * ans;
    }
}
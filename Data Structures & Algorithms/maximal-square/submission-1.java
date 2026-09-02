class Solution {
    public int maximalSquare(char[][] matrix) {
        int ROWS = matrix.length, COLS = matrix[0].length, ans = 0;
        int[][] dp = new int[ROWS][COLS];

        for (int r = 0; r < ROWS; r++) {
            dp[r][0] = matrix[r][0] - '0';
            ans = Math.max(ans, dp[r][0]);
        }

        for (int c = 0; c < COLS; c++) {
            dp[0][c] = matrix[0][c] - '0';
            ans = Math.max(ans, dp[0][c]);
        }

        for (int r = 1; r < ROWS; r++) {
            for (int c = 1; c < COLS; c++) {
                if (matrix[r][c] == '0') {
                    dp[r][c] = 0;
                }
                else {
                    dp[r][c] = 1 + Math.min(dp[r - 1][c - 1], Math.min(dp[r - 1][c], dp[r][c - 1]));
                    ans = Math.max(ans, dp[r][c]);
                }
            }
        }

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                System.out.print(dp[r][c] + " ");
            }
            System.out.println();
        }

        return ans * ans;
    }
}
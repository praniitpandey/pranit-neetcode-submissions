public class Solution {
    private int[][] dp;

    public int maximalSquare(char[][] matrix) {
        int ROWS = matrix.length, COLS = matrix[0].length;
        dp = new int[ROWS][COLS];
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                dp[i][j] = -1;
            }
        }

        dfs(0, 0, matrix);
        int maxSquare = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                maxSquare = Math.max(maxSquare, dp[i][j]);
            }
        }
        return maxSquare * maxSquare;
    }

    private int dfs(int r, int c, char[][] matrix) {
        if (r >= matrix.length || c >= matrix[0].length) {
            return 0;
        }
        if (dp[r][c] != -1) {
            return dp[r][c];
        }
        int down = dfs(r + 1, c, matrix);
        int right = dfs(r, c + 1, matrix);
        int diag = dfs(r + 1, c + 1, matrix);
        dp[r][c] = 0;
        if (matrix[r][c] == '1') {
            dp[r][c] = 1 + Math.min(down, Math.min(right, diag));
        }
        return dp[r][c];
    }
}
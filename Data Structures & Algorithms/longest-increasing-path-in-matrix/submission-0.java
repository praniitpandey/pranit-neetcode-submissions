class Solution {
    private int ROWS;
    private int COLS;
    private int[][] dp;

    public int longestIncreasingPath(int[][] matrix) {
        ROWS = matrix.length;
        COLS = matrix[0].length;
        dp = new int[ROWS][COLS];

        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        int longestPathHere, longestPathOverall = 1;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                longestPathHere = dfs(matrix, r, c);
                longestPathOverall = Math.max(longestPathHere, longestPathOverall);
                System.out.print(dp[r][c] + " ");
            }
            System.out.println();
        }

        return longestPathOverall;
    }

    private int dfs(int[][] matrix, int r, int c) {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
            return 0;
        }

        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        int longestPathHere = 1;
        int[] dirs = {0, 1, 0, -1, 0};

        for (int i = 1; i < 5; i++) {
            int nr = r + dirs[i - 1];
            int nc = c + dirs[i];

            if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS)
                continue;

            if (matrix[nr][nc] > matrix[r][c])
                longestPathHere = Math.max(longestPathHere, 1 + dfs(matrix, nr, nc));
        }

        return dp[r][c] = longestPathHere;
    }
}

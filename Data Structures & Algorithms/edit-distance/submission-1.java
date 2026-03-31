class Solution {
    private int[][] dp;
    private int dfs(String text1, String text2, int i, int j) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (i == text1.length()) {
            return text2.length() - j;
        }
        if (j == text2.length()) {
            return text1.length() - i;
        }
        
        if (text1.charAt(i) == text2.charAt(j)) {
            return dp[i][j] = dfs(text1, text2, i + 1, j + 1);
        }

        int res = Math.min(dfs(text1, text2, i + 1, j), dfs(text1, text2, i, j + 1));
        res = Math.min(res, dfs(text1, text2, i + 1, j + 1));
        return dp[i][j] = res + 1;
    }

    public int minDistance(String text1, String text2) {
        dp = new int[text1.length() + 1][text2.length() + 1];
        for (int r = 0; r <= text1.length(); r++) {
            for (int c = 0; c <= text2.length(); c++) {
                dp[r][c] = -1;
            }
        }
        return dfs(text1, text2, 0, 0);   
    }
}

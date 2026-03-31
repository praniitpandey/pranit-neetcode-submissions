class Solution {
    int[][] dp;
    public int numDistinct(String s, String t) {
        if (s.length() < t.length())
            return 0;

        if (s.length() == t.length())
            return s.equals(t) ? 1 : 0;

        dp = new int[s.length() + 1][t.length() + 1];
        for (int r = 0; r <= s.length(); r++) {
            for (int c = 0; c <= t.length(); c++) {
                dp[r][c] = -1;
            }
        }

        return dfs(s, t, 0, 0);
    }

    private int dfs(String s, String t, int i, int j) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (j == t.length()) {
            return dp[i][j] = 1;
        }
        if (i == s.length()) {
            return dp[i][j] = 0;
        }

        int ifNotPicked = dfs(s, t, i + 1, j);
        int ifPicked = 0;

        if (s.charAt(i) == t.charAt(j)) {
            ifPicked = dfs(s, t, i + 1, j + 1);
        }

        return dp[i][j] = ifNotPicked + ifPicked;
    }
}

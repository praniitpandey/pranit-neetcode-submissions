class Solution {
    private int[] dp;

    public int numSquares(int n) {
        dp = new int[n + 1];
        Arrays.fill(dp, -1);
        return solve(n);
    }

    private int solve(int n) {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int ans = Integer.MAX_VALUE;
        for (int i = (int)Math.sqrt(n); i > 0; i--) {
            ans = Math.min(ans, 1 + solve(n - i * i));
        }
        return dp[n] = ans;
    }
}
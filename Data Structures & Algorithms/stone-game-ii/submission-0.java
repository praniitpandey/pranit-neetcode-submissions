class Solution {
    private int[][] dp;

    public int stoneGameII(int[] piles) {
        dp = new int[piles.length][piles.length + 1];
        for (int[] row : dp)
            Arrays.fill(row, Integer.MIN_VALUE);
        
        int totalScore = 0, netScore = solve(piles, 0, 1);
        for (int pile : piles)
            totalScore += pile;

        return (totalScore + netScore) / 2;
    }

    private int solve(int[] piles, int index, int m) {
        if (index == piles.length) {
            return 0;
        }

        if (dp[index][m] != Integer.MIN_VALUE) {
            return dp[index][m];
        }

        int pileSum = 0, netPick, maxNetPick = Integer.MIN_VALUE;

        for (int x = 1; x <= 2*m && index + x - 1 < piles.length; x++) {
            pileSum += piles[index + x - 1];
            netPick = pileSum - solve(piles, index + x, Math.max(m, x));
            maxNetPick = Math.max(netPick, maxNetPick);
        }

        return dp[index][m] = maxNetPick;
    }
}
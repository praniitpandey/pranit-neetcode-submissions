class Solution {
    public String stoneGameIII(int[] stoneValue) {

        long dp[] = new long[stoneValue.length];
        Arrays.fill(dp, Long.MIN_VALUE);

        long netScore = solve(stoneValue, 0, dp);
        
        System.out.println(netScore);

        if (netScore > 0) {
            return "Alice";
        }
        else if (netScore < 0) {
            return "Bob";
        }
        else {
            return "Tie";
        }
    }

    private long solve(int[] stoneValue, int index, long[] dp) {
        int n = stoneValue.length;

        if (index == n) {
            return 0;
        }

        if (dp[index] != Long.MIN_VALUE) {
            return dp[index];
        }

        long pickedSum = 0L, netScore = 0L, maxNetScore = Long.MIN_VALUE;
        for (int i = index; i < index + 3 && i < n; i++) {
            pickedSum += stoneValue[i];

            netScore = pickedSum - solve(stoneValue, i + 1, dp);
            maxNetScore = Math.max(netScore, maxNetScore);
        }

        return dp[index] = maxNetScore;
    }
}
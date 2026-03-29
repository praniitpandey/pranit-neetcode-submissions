class Solution {
public:
    int numWays(int n, int k) {
        if (n == 1) {
            return k;
        }
        if (n == 2) {
            return k * k;
        }

        int dp1 = k, dp2 = k * k, dp3;

        for (int i = 3; i <= n; i++) {
            dp3 = (dp2 + dp1) * (k - 1);
            dp1 = dp2;
            dp2 = dp3;
        }

        return dp2;
    }
};
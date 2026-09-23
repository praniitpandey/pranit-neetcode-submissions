class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 2, 0);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0')
                dp[i] = 0;
            else if (s[i] == '1')
                dp[i] = dp[i + 1] + (i < n - 1 ? dp[i + 2] : 0);
            else if (s[i] == '2')
                dp[i] = dp[i + 1] + (i < n - 1 && s[i + 1] <= '6' ? dp[i + 2] : 0);
            else
                dp[i] = dp[i + 1];
        }

        return dp[0];
    }
};
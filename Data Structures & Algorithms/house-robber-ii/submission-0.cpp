class Solution {
public:
    int rob(vector<int>& m) 
    {
        int n = m.size();
        
        if (n == 1)
            return m[0];
        if (n == 2)
            return max(m[0], m[1]);
        
        vector<int> m1(m.begin(), m.begin() + n - 1);
        vector<int> m2(m.begin() + 1, m.begin() + n);
        
        return max(rob1(m1), rob1(m2));        
    }
    
    int rob1(vector<int>& m) 
    {
        int n = m.size();
        
        if (n == 1)
            return m[0];
        if (n == 2)
            return max(m[0], m[1]);
        if (n == 3)
            return max(m[0] + m[2], m[1]);
        
        vector<int> dp(n, 0);
        dp[0] = m[0];
        dp[1] = m[1];
        dp[2] = max(m[0] + m[2], m[1]);
        
        for (int i = 3; i < n; ++i)
            dp[i] = m[i] + max(dp[i - 2], dp[i - 3]);
        
        return max(dp[n - 1], dp[n - 2]);          
    }
};
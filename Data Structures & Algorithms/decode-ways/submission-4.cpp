class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        int ways0, ways1, ways2;

        ways1 = (s[0] == '0' ? 0 : 1);
        ways0 = ways1;

        for (int i = 1; i < n; i++) {
            ways0 = (s[i] == '0' ? 0 : ways1);
            int prev_ways = (i >= 2 ? ways2 : 1);
            if (s[i - 1] == '1') {
                ways0 += prev_ways;
            }
            else if (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6') {
                ways0 += prev_ways;
            }

            ways2 = ways1;
            ways1 = ways0;
        }
        
        return ways0;
    }
};

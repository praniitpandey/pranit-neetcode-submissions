class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> ways(n, 0);

        ways[0] = (s[0] == '0' ? 0 : 1);

        for (int i = 1; i < n; i++) {
            ways[i] = (s[i] == '0' ? 0 : ways[i - 1]);
            int prev_ways = (i >= 2 ? ways[i - 2] : 1);
            if (s[i - 1] == '1') {
                ways[i] += prev_ways;
            }
            else if (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6') {
                ways[i] += prev_ways;
            } 
        }
        
        return ways[n-1];
    }
};

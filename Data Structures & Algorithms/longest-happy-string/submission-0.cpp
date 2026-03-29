class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        long long n = a + b + c;
        string ans = "";

        for (long long i = 0; i < n; i++) {
            string last2 = (ans.length() >= 2) ? ans.substr(ans.length() - 2, 2) : "";

            if ((a >= b && a >= c && last2 != "aa") || (a > 0 && (last2 == "bb" || last2 == "cc"))) {
                ans += "a";
                a--;
            }
            else if ((b >= a && b >= c && last2 != "bb") || (b > 0 && (last2 == "aa" || last2 == "cc"))) {
                ans += "b";
                b--;
            }
            else if ((c >= a && c >= b && last2 != "cc") || (c > 0 && (last2 == "aa" || last2 == "bb"))) {
                ans += "c";
                c--;
            }
            else {
                break;
            }
        }

        return ans;        
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        if (n == 1) {
            return s;
        }
        int maxLength = -1;
        string maxString = "";
        int left, right;

        for (int i = 0; i < n; i++) {
            //for odd length palindromes
            left = i, right = i;
            while (left >= 0 && right < n) {
                if (s[left] != s[right]) {
                    break;
                }
                left--;
                right++;
            }
            ++left;
            --right;
            if ((right - left + 1) > maxLength) {
                maxLength = right - left + 1;
                maxString = s.substr(left, right - left + 1);
            }

            //for even length palindromes
            left = i, right = i + 1;

            while (left >= 0 && right < n) {
                if (s[left] != s[right]) {
                    break;
                }
                left--;
                right++;
            }
            ++left;
            --right;
            if ((right - left + 1) > maxLength) {
                maxLength = right - left + 1;
                maxString = s.substr(left, right - left + 1);
            }
        }
        
        return maxString;
    }
};
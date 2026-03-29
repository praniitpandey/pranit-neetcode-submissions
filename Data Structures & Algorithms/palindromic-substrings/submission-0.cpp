class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        int left, right;

        for (int i = 0; i < n; i++) {
            //for odd length substrings
            left = i, right = i;

            while (left >= 0 && right < n) {
                if (s[left] == s[right]) {
                    ++count;
                }
                else {
                    break;
                }
                left--, right++;
            }

            //for even length substrings
            left = i, right = i + 1;

            while (left >= 0 && right < n) {
                if (s[left] == s[right]) {
                    ++count;
                }
                else {
                    break;
                }
                left--, right++;
            }
        }
        
        return count;
    }
};

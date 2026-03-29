class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;

        int l = 0, length, max_length = 0;

        for (int r = 0; r < s.size(); r++) {
            ++freq[s[r]];

            while (freq[s[r]] > 1) {
                --freq[s[l]];
                l++;
            }

            length = r - l + 1;
            max_length = max(length, max_length);
        }

        return max_length;
    }
};

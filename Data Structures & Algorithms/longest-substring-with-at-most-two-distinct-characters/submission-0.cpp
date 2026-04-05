class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s, int k = 2) {
        int left = 0, maxLength = 0;
        unordered_map<char, int> freq;

        for (int right = 0; right < s.size(); right++) {
            ++freq[s[right]];

            while (freq.size() > k) {
                --freq[s[left]];
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }

                ++left;
            }

            maxLength = max(right - left + 1, maxLength);
        }
        return maxLength;
    }
};
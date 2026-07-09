class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char, int> freq;
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            ++freq[s[right]];

            while (freq[s[right]] > 1) {
                --freq[s[left]];
                ++left;
            }

            maxLength = max(right - left + 1, maxLength);
        }

        return maxLength;
    }
};
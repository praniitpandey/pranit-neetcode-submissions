class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int right, left = 0, maxFreq = 0, maxLength = 1;

        for (right = 0; right < s.size(); right++) {
            ++freq[s[right]];
            maxFreq = max(freq[s[right]], maxFreq);

            while ((right - left + 1) - maxFreq > k) {
                --freq[s[left]];
                ++left;
            }

            maxLength = max((right - left + 1), maxLength);
        }
        
        return maxLength;
    }
};

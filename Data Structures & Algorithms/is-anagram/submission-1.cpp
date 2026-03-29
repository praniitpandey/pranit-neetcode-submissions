class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        map<char, int> sfreq;
        map<char, int> tfreq;
        for (int i = 0; i < s.length(); i++) {
            ++sfreq[s[i]];
            ++tfreq[t[i]];
        }

        return (sfreq == tfreq);
    }
};

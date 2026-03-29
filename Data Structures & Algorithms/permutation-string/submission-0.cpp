class Solution {
public:
    bool checkInclusion(string w, string s) {
        int wSize = w.size();
        int sSize = s.size();

        if (sSize < wSize) {
            return false;
        }

        vector<int> wFreq(26, 0);
        vector<int> sFreq(26, 0);
        for (int i = 0; i < wSize; i++) {
            ++wFreq[w[i] - 'a'];
            ++sFreq[s[i] - 'a'];
        }

        for (int i = 0; i < (sSize - wSize) ; i++) {
            if (isPermutation(wFreq, sFreq)) {
                return true;
            }

            --sFreq[s[i] - 'a'];
            ++sFreq[s[i + wSize] - 'a'];
        }

        return isPermutation(wFreq, sFreq);
    }

    inline bool isPermutation(const vector<int>& freq1, const vector<int>& freq2) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }
};
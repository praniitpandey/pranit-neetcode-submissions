class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> tFreq;
        unordered_map<char, int> sFreq;
        for (char c : t) {
            ++tFreq[c];
        }

        int left = 0;
        int minLeft = 1e9, minLength = 1e9;

        for (int right = 0; right < s.size(); right++) {
            ++sFreq[s[right]];

            while (isPresent(tFreq, sFreq)) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minLeft = left;
                }

                --sFreq[s[left]];
                ++left;
            }
        }

        if (minLeft == 1e9) {
            return "";
        }
        else {
            return s.substr(minLeft, minLength);
        }
    }

    bool isPresent(const unordered_map<char, int>& tFreq, const unordered_map<char, int>& sFreq) {

        for (auto& [currChar, currFreq] : tFreq) {
            auto it = sFreq.find(currChar);

            if (it == sFreq.end() || it->second < currFreq) {
                return false;
            }
        }

        return true;
    }
};

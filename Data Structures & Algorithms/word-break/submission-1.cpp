class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        vector<int> cache(s.size(), -1);
        for (string word : wordDict) {
            dict.insert(word);
        }

        return wordBreak(s, dict, 0, cache);
    }

    bool wordBreak(string s, const unordered_set<string>& dict, int i, vector<int>& cache) {
        if (i == s.size()) {
            return true;
        }

        if (cache[i] != -1) {
            return cache[i] == 1;
        }

        for (int j = i; j < s.size(); j++) {
            if (dict.find(s.substr(i, j - i + 1)) != dict.end()) {
                if (wordBreak(s, dict, j + 1, cache)) {
                    cache[i] = 1;
                    return true;
                }
            }
        }

        cache[i] = 0;
        return false;
    }
};

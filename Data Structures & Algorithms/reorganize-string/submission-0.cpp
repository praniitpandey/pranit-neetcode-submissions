class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            ++freq[c];
        }

        auto cmp = [](pair<char, int> a, pair<char, int> b) {
            return a.second < b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> maxFreq(cmp);

        for (auto it : freq) {
            maxFreq.push(make_pair(it.first, it.second));
        }

        string ans = "";
        while (!maxFreq.empty()) {
            auto [char1, freq1] = maxFreq.top();
            maxFreq.pop();

            if (ans.empty() || ans.back() != char1) {
                ans = ans + char1;
                if (--freq1) {
                    maxFreq.push(make_pair(char1, freq1));
                }
            }
            else {
                if (maxFreq.empty()) {
                    return "";
                }

                auto [char2, freq2] = maxFreq.top();
                maxFreq.pop();

                ans = ans + char2;
                if (--freq2) {
                    maxFreq.push(make_pair(char2, freq2));
                }
                maxFreq.push(make_pair(char1, freq1));
            }
        }


        return ans;        
    }
};
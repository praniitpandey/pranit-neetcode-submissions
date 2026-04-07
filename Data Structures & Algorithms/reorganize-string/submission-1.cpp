class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            ++freq[c];
        }

        priority_queue<pair<int, char>> freqHeap;
        for (auto it : freq) {
            freqHeap.push(make_pair(it.second, it.first));
        }

        string ans = "";
        while (!freqHeap.empty()) {
            auto [highestFreq, highestChar] = freqHeap.top();
            freqHeap.pop();

            if (ans.empty() || ans.back() != highestChar) {
                ans += highestChar;
                --highestFreq;

            }
            else {
                if (freqHeap.empty()) {
                    return "";
                }

                auto [secondHighestFreq, secondHighestChar] = freqHeap.top();
                freqHeap.pop();

                ans += secondHighestChar;
                --secondHighestFreq;

                if (secondHighestFreq > 0) {
                    freqHeap.push(make_pair(secondHighestFreq, secondHighestChar));
                }
            }
            if (highestFreq > 0) {
                freqHeap.push(make_pair(highestFreq, highestChar));
            }
        }

        return ans;
    }
};
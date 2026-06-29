class Solution {
private:
    unordered_map<char, int> orderMap;

    bool isCorrectOrder(const string& word1, const string& word2) {
        for (int i = 0; i < word1.size() && word2.size(); i++) {
            int rank1 = orderMap[word1[i]], rank2 = orderMap[word2[i]];

            if (rank1 < rank2) {
                return true;
            }
            else if (rank1 > rank2) {
                return false;
            }
        }

        return (word1.size() <= word2.size());
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i = 0; i < order.size(); i++) {
            orderMap[order[i]] = i;
        }
        
        for (int i = 1; i < words.size(); i++) {
            if (!isCorrectOrder(words[i - 1], words[i])) {
                return false;
            }
        }

        return true;
    }
};
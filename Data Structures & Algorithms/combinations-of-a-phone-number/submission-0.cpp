class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> ans = {""};
        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        for (char d : digits) {
            string s = letters[d - '0'];
            vector<string> temp;
            for (string combo : ans) {
                for (char c : s) {
                    temp.push_back(combo + c);
                }
            }
            ans = temp;
        }

        return ans;
    }
};
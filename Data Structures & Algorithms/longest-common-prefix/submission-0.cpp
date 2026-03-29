class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_length = strs[0].length();

        for (int i = 1; i < strs.size(); i++) {
            min_length = min((int)strs[i].length(), min_length);
        }

        string prefix = "";
        for (int i = 0; i < min_length; i++) {
            char currentChar = strs[0][i];
            bool isCommon = true;
            for (int j = 1; j < strs.size(); j++) {
                if (currentChar != strs[j][i]) {
                    isCommon = false;
                    break;
                }
            }

            if (isCommon) {
                prefix = prefix + currentChar;
            }
            else {
                break;
            }
        }

        return prefix;        
    }
};
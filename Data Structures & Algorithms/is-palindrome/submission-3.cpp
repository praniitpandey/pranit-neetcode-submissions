class Solution {
public:
    bool isPalindrome(string s) {

        string transformed = "";
        for (char c : s) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                if (c >= 'a' && c <= 'z') {
                    c -= ('a' - 'A');
                }
                transformed = transformed + c;
            }
        }

        cout << transformed;

        string reversed = "";
        for (char c : transformed) {
            reversed = c + reversed;
        }
        
        return (transformed == reversed);
    }
};

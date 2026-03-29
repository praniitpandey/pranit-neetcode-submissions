class Solution {
public:
    bool checkValidString(string s) {
        stack<int> brackets;
        stack<int> stars;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                brackets.push(i);
            }
            else if (s[i] == ')') {
                if (!brackets.empty()) {
                    brackets.pop();
                }
                else if (!stars.empty() && stars.top() < i) {
                    stars.pop(); //replacing right bracktes with valid position stars
                }
                else {
                    return false;
                }
            }
            else if (s[i] == '*') {
                stars.push(i);
            }
        }

        while (!brackets.empty() && !stars.empty()) {
            if (stars.top() > brackets.top()) {
                brackets.pop();
                stars.pop(); //replacing left bracktes with valid position stars
            }
            else {
                return false; //star position is invalid
            }
        }
        
        return brackets.empty();
    }
};

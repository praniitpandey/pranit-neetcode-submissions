class Solution {
public:
    int calculate(string s) {
        auto evaluate = [](int x, int y, char op) -> int {
            if (op == '+') {
                return x;
            }
            if (op == '-') {
                return -x;
            }
            if (op == '*') {
                return x * y;
            }
            return x / y;
        };

        vector<pair<int, bool>> stack;  // {value, isInt}
        int curr = 0;
        char previousOperator = '+';
        s += "@";

        for (char c : s) {
            if (isdigit(c)) {
                curr = curr * 10 + (c - '0');
            } else if (c == '(') {
                stack.push_back({previousOperator, false});
                previousOperator = '+';
            } else {
                if (previousOperator == '*' || previousOperator == '/') {
                    int top = stack.back().first;
                    stack.pop_back();
                    stack.push_back({evaluate(top, curr, previousOperator), true});
                } else {
                    stack.push_back({evaluate(curr, 0, previousOperator), true});
                }

                curr = 0;
                previousOperator = c;

                if (c == ')') {
                    while (!stack.empty() && stack.back().second) {
                        curr += stack.back().first;
                        stack.pop_back();
                    }
                    previousOperator = stack.back().first;
                    stack.pop_back();
                }
            }
        }

        int ans = 0;
        for (auto& p : stack) {
            ans += p.first;
        }

        return ans;
    }
};
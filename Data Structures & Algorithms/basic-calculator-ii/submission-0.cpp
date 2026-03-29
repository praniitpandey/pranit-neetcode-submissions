class Solution {
public:
    int calculate(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        stack<int> st;
        char op = '+';
        int num = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            }
            if (!(s[i] >= '0' && s[i] <= '9') || (i == s.size() - 1)) {
                if (op == '+') {
                    st.push(num);
                }
                else if (op == '-') {
                    st.push(num * -1);
                }
                else if (op == '/') {
                    int prev = st.top();
                    st.pop();

                    st.push(prev / num);
                }
                else if (op == '*') {
                    int prev = st.top();
                    st.pop();

                    st.push(prev * num);
                }

                op = s[i];
                num = 0;
            }
        }

        long long ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
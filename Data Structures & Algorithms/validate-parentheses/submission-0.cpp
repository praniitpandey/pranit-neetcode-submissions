class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char cb = s[i];

            if (cb == '(' || cb == '{' || cb == '[') {
                st.push(cb);
            }
            else if (cb == ')') {
                if (st.empty()) {
                    return false;
                }
                else if (st.top() == '(') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else if (cb == '}') {
                if (st.empty()) {
                    return false;
                }
                else if (st.top() == '{') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else if (cb == ']') {
                if (st.empty()) {
                    return false;
                }
                else if (st.top() == '[') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
            
        } //end of for loop

        if (st.empty()) {
            return true;
        }
        else {
            return false;
        }
        
    } //end of function
};

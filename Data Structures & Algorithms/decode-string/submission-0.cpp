class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                string num = "";
                num += s[i];

                while (i + 1 < s.size() && s[i + 1] >= '0' && s[i + 1] <= '9') {
                    num += s[++i];
                }

                st.push(num);
            }
            else if (s[i] == '[') {
                st.push("[");
            }
            else if (s[i] >= 'a' && s[i] <= 'z') {
                string letter = "";
                letter += s[i];
                st.push(letter);
            }
            else if (s[i] == ']') {
                string seg = "", rep = "";

                while (!st.empty()) {
                    if (st.top() == "[") {
                        st.pop();
                        break;
                    }
                    else {
                        seg = st.top() + seg;
                        st.pop();
                    }
                }

                int times = stoi(st.top());
                st.pop();

                for (int j = 0; j < times; j++) {
                    rep += seg;
                }
                st.push(rep);
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};
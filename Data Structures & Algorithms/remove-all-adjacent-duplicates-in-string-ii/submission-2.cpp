class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        st.push(make_pair(s[0], 1));
        for (int i = 1; i < s.length(); i++) {
            int currFreq = 1;
            if (!st.empty()) {
                auto [lastChar, lastFreq] = st.top();
                if (s[i] == lastChar) {
                    st.pop();
                    currFreq = ++lastFreq;
                }
            }

            if (currFreq % k > 0) {
                st.push(make_pair(s[i], currFreq));
            }
        }

        string ans = "";

        while (!st.empty()) {
            auto [currChar, currFreq] = st.top();
            st.pop();

            for (int i = 0; i < currFreq; i++) {
                ans.push_back(currChar);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;        
    }
};
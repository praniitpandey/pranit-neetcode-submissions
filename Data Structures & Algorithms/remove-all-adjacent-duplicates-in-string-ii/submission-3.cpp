class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        st.push(make_pair('#', 1));
        for (char c : s) {
            int currFreq = 1;
            if (!st.empty()) {
                auto [lastChar, lastFreq] = st.top();
                if (c == lastChar) {
                    st.pop();
                    currFreq = ++lastFreq;
                }
            }

            if (currFreq % k > 0) {
                st.push(make_pair(c, currFreq));
            }
        }

        string ans = "";

        while (st.size() > 1) {
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
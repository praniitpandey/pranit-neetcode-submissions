class Solution {
public:
    vector<string> restoreIpAddresses(const string s) {
        vector<string> ans;
        if (s.size() > 12) {
            return ans;
        }

        auto valid = [&](string& num) {
            if (num.size() > 1 && num[0] == '0') return false;
            int value = stoi(num);
            return value <= 255;
        };

        for (int seg1 = 1; seg1 <= 3; seg1++) {
            for (int seg2 = 1; seg2 <= 3; seg2++) {
                for (int seg3 = 1; seg3 <= 3; seg3++) {
                    for (int seg4 = 1; seg4 <= 3; seg4++) {
                        if (seg1 + seg2 + seg3 + seg4 == s.size()) {
                            string ip1 = s.substr(0, seg1);
                            string ip2 = s.substr(seg1, seg2);
                            string ip3 = s.substr(seg1 + seg2, seg3);
                            string ip4 = s.substr(seg1 + seg2 + seg3, seg4);

                            if (valid(ip1) && valid(ip2) && valid(ip3) && valid(ip4)) {
                                ans.push_back(ip1 + "." + ip2 + "." + ip3 + "." + ip4);
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};
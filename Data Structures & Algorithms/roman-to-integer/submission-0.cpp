class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> value;
        value["I"] = 1;
        value["V"] = 5;
        value["X"] = 10;
        value["L"] = 50;
        value["C"] = 100;
        value["D"] = 500;
        value["M"] = 1000;
        value["IV"] = 4; 
        value["IX"] = 9; 
        value["XL"] = 40; 
        value["XC"] = 90; 
        value["CD"] = 400; 
        value["CM"] = 900;

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            string parse = "";
            parse += s[i];
            if ((s[i] == 'I') && (i < s.size() - 1) && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                parse += s[i + 1];
                ++i;
            }
            else if ((s[i] == 'X') && (i < s.size() - 1) && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                parse += s[i + 1];
                ++i;
            }
            else if ((s[i] == 'C') && (i < s.size() - 1) && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                parse += s[i + 1];
                ++i;
            }
            else {
            }
            ans += value[parse];
        }

        return ans;        
    }
};
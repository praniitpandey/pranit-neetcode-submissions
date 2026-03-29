class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> symbol;
        symbol[1] = "I";
        symbol[4] = "IV";
        symbol[5] = "V";
        symbol[9] = "IX";
        symbol[10] = "X";
        symbol[40] = "XL";
        symbol[50] = "L";
        symbol[90] = "XC";
        symbol[100] = "C";
        symbol[400] = "CD";
        symbol[500] = "D";
        symbol[900] = "CM";
        symbol[1000] = "M";

        string ans = "";

        while (num > 0) {
            int red = 0;
            if (num >= 1000) {
                red = 1000;
            }
            else if (num >= 900) {
                red = 900;
            }
            else if (num >= 500) {
                red = 500;
            }
            else if (num >= 400) {
                red = 400;
            }
            else if (num >= 100) {
                red = 100;
            }
            else if (num >= 90) {
                red = 90;
            }
            else if (num >= 50) {
                red = 50;
            }
            else if (num >= 40) {
                red = 40;
            }
            else if (num >= 10) {
                red = 10;
            }
            else if (num >= 9) {
                red = 9;
            }
            else if (num >= 5) {
                red = 5;
            }
            else if (num >= 4) {
                red = 4;
            }
            else if (num >= 1) {
                red = 1;
            }

            ans += symbol[red];
            num -= red;
        }

        return ans;
    }
};
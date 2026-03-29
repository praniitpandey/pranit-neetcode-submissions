class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;
        int original_x = x;
        x = abs(x);
        vector<int> max_digits = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
        vector<int> x_digits;
        while (x > 0) {
            x_digits.push_back(x % 10);
            x /= 10;
        }
        int n = max_digits.size();

        if (x_digits.size() == n) {
            for (int i = 0; i < n; i++) {
                if (x_digits[i] < max_digits[i]) break;
                if (x_digits[i] > max_digits[i]) return 0;
            }
        }

        int result = 0;
        for (int digit : x_digits) {
            result = result * 10 + digit;
        }

        return original_x < 0 ? -result : result;        
    }
};
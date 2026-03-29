class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        else if (n == 1) {
            return x;
        }
        else if (n > 1) {
            return myPow(x, n - 1) * x;
        }
        else {
            return myPow(x, n + 1) / x;
        } //else if (n < 0) might throw error
    }
};

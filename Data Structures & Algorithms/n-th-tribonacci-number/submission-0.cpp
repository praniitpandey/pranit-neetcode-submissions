class Solution {
public:
    int tribonacci(int n) {
        switch (n) {
            case 0: return 0;
            case 1: return 1;
            case 2: return 1;
            default: break;
        }

        int a = 0, b = 1, c = 1, d = 0;
        for (int i = 3; i <=n; i++) {
            d = c + b + a;
            a = b;
            b = c;
            c = d;
        }

        return d;
    }
};
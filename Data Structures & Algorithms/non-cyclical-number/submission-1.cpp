class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) {
            return true;
        }

        int sum;
        unordered_set<int> sums;
        sums.insert(n);

        while (true) {
            sum = 0;
            while (n > 0) {
                sum += ((n%10) * (n%10));
                n /= 10;
            }
            if (sum == 1) {
                return true;
            }
            else {
                if (sums.find(sum) != sums.end()) {
                    return false;
                }
                sums.insert(sum);
                n = sum;
            }
        }

        return false;        
    }
};

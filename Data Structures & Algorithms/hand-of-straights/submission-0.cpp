class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize != 0) {
            return false;
        }

        vector<int> freq(1001, 0);
        for (int h : hand) {
            ++freq[h];
        }
        int currentMinFreq;

        for (int i = 0; i <= 1000; i++) {
            if (freq[i] > 0) {
                currentMinFreq = freq[i];
                for (int j = 0; j < groupSize; j++) {
                    if (i + j > 1000 || freq[i + j] < currentMinFreq) {
                        return false;
                    }
                    freq[i + j] -= currentMinFreq;
                }
                i--;
            }
        }

        return true;        
    }
};
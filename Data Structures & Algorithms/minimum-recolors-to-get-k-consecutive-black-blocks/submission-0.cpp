class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length(), w = 0, b = 0;
        int left = 0, right = 0;

        for (right = 0; right < k && right < n; right++) {
            if (blocks[right] == 'W') {
                ++w;
            }
            else {
                ++b;
            }
        }

        int minW = w;
        for (left = 0, right = k; right < n; left++, right++) {
            minW = min(w, minW);

            if (blocks[right] == 'W') {
                ++w;
            }
            else {
                ++b;
            }

            if (blocks[left] == 'W') {
                --w;
            }
            else {
                --b;
            }
        }

        return minW;
    }
};
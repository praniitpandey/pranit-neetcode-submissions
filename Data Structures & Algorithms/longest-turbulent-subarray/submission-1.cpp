class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return arr[0] == arr[1] ? 1 : 2;
        }

        int direction = 0;
        int max_ending_here = 1, max_overall = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] < arr[i]) {
                if (direction == 0) {
                    direction = 1;
                    max_ending_here = 2;
                }
                else if (direction == 1) {
                    direction = 1;
                    max_ending_here = 2;
                }
                else if (direction == -1) {
                    direction = 1;
                    ++max_ending_here;
                }
            }
            else if (arr[i - 1] == arr[i]) {
                max_ending_here = 1;
                direction = 0;
            }
            else if (arr[i - 1] > arr[i]) {
                if (direction == 0) {
                    direction = -1;
                    max_ending_here = 2;
                }
                else if (direction == -1) {
                    direction = -1;
                    max_ending_here = 2;
                }
                else if (direction == 1) {
                    direction = -1;
                    ++max_ending_here;
                }
            }
            max_overall = max(max_ending_here, max_overall);
        }

        return max_overall;
    }
};
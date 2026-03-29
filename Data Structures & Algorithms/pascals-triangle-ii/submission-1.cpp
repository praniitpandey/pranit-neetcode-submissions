class Solution {
public:
    vector<int> getRow(int n) {
        if (n == 0) return {1};
        vector<int> prevRow = {1};
        vector<int> currRow = {1, 1};

        for (int i = 1; i <= n; i++) {
            currRow.resize(i + 1, 1);
            for (int j = 1; j < i; j++) {
                currRow[j] = prevRow[j - 1] + prevRow[j];
            }
            prevRow = currRow;
        }

        return prevRow;
    }
};
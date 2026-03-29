class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int L = INT_MAX, R = INT_MIN;
        unordered_map<int, int> up;
        unordered_map<int, int> down;

        for (vector<int> trip : trips) {
            L = min(L, trip[1]);
            up[trip[1]] += trip[0];
            R = max(R, trip[2]);
            down[trip[2]] += trip[0];
        }
        
    int current = 0;
        for (int i = L; i <= R; i++) {
            if (down.find(i) != down.end()) {
                current -= down[i];
            }

            if (up.find(i) != up.end()) {
                current += up[i];
            }

            if (current > capacity) {
                return false;
            }
        }

        return true;
    }
};
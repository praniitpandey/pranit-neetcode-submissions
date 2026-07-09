class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> rightBoundary(n, -1);
        rightBoundary[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightBoundary[i] = max(height[i], rightBoundary[i + 1]);
        }

        vector<int> leftBoundary(n, -1);
        leftBoundary[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftBoundary[i] = max(height[i], leftBoundary[i - 1]);
        }

        int water = 0;
        for (int i = 0; i < n; i++) {
            int minBoundary = min(leftBoundary[i], rightBoundary[i]);
            water += (minBoundary - height[i]);
        }

        return water;
    }
};
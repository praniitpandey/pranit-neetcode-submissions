class Solution {
public:
    int maxWidthRamp(vector<int>& height) {
        int n = height.size();

        vector<int> rightMax(n, -1);
        rightMax[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (height[i] > height[rightMax[i + 1]])
                rightMax[i] = i;
            else
                rightMax[i] = rightMax[i + 1];
        }

        int left = 0, right = 0, maxWidth = 0;
        while (right < n) {
            if (height[left] <= height[rightMax[right]]) {
                maxWidth = max(maxWidth, right - left);
                right++;
            } else {
                left++;
            }
        }
        return maxWidth;
    }
};
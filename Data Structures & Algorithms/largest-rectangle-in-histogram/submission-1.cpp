class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int area = 0, minLeftHeight = 0, maxArea = 0;
        for (int i = 0; i < n; i++) {
            minLeftHeight = heights[i];
            for (int j = i; j < n; j++) {
                if (heights[j] == 0) {
                    break;
                }
                minLeftHeight = min(minLeftHeight, heights[j]);
                area = (j - i + 1) * minLeftHeight;
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};

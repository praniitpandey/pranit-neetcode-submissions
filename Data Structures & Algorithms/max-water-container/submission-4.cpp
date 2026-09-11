class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1, area = 0, maxArea = 0;

        while (left < right) {
            area = (right - left) * min(heights[right], heights[left]);
            maxArea = max(area, maxArea);

            if (heights[left] > heights[right])
                right--;
            else
                left++;
        }

        return maxArea;
    }
};

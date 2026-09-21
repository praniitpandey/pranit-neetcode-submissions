class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        if (n == 0)
            return 0;

        int left = 0, right = n - 1, leftMax = height[left], rightMax = height[right], ans = 0;

        while (left < right) {
            if (leftMax < rightMax) {
                left++;
                leftMax = max(leftMax, height[left]);
                ans += (leftMax - height[left]);
            }
            else {
                right--;
                rightMax = max(rightMax, height[right]);
                ans += (rightMax - height[right]);
            }
        }

        return ans;
    }
};
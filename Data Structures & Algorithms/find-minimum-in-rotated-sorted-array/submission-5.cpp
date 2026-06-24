class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1, mid, ans = INT_MAX;

        while (left <= right) {
            mid = left + (right - left)/2;
            ans = min(nums[mid], ans);

            if (nums[left] <= nums[mid]) {
                ans = min(nums[left], ans);
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;        
    }
};
class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1, ans = nums[0], mid;

        while (left <= right) {
            if (nums[left] <= nums[right]) {
                ans = min(ans, nums[left]);
                break;
            }

            mid = left + (right - left)/2;

            if (nums[left] <= nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
                ans = min(ans, nums[mid]);
            }
        }

        return ans;        
    }
};

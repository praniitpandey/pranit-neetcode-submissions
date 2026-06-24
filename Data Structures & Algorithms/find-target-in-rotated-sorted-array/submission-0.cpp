class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;

        while (left < right) {
            mid = left + (right - left)/2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        int pivot = left;

        if (target >= nums[pivot] && target <= nums[nums.size() - 1]) {
            left = pivot;
            right = nums.size() - 1;
        }
        else {
            left = 0;
            right = pivot - 1;
        }

        while (left <= right) {
            mid = left + (right - left)/2;

            if (target > nums[mid]) {
                left = mid + 1;
            }
            else if (target < nums[mid]) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }

        return -1;
    }
};
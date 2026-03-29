class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};
        
        int left = 0, right = n - 1, mid = 0;
        int lowerBound = 0, upperBound = 0;

        while (left <= right) {
            mid = left + (right - left)/2;

            if (target > nums[mid]) {
                left = mid + 1;
            }
            else if (target <= nums[mid]) {
                right = mid - 1;
                lowerBound = mid;
            }
        }
        lowerBound = nums[lowerBound] == target ? lowerBound : -1;

        left = 0, right = n - 1, mid = 0;
        while (left <= right) {
            mid = left + (right - left)/2;

            if (target < nums[mid]) {
                right = mid - 1;
            }
            else if (target >= nums[mid]) {
                left = mid + 1;
                upperBound = mid;
            }
        }
        upperBound = nums[upperBound] == target ? upperBound : -1;

        return vector<int>{lowerBound, upperBound};
    }
};
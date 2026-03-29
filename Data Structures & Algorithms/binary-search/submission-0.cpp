class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1, mid;

        while (i <= j)
        {
            mid = (i + j) / 2;
            if (target > nums[mid]) {
                i = mid + 1;
            }
            else if (target < nums[mid]) {
                j = mid - 1;
            }
            else {
                return mid;
            }
        }
        
        return -1;
    }
};

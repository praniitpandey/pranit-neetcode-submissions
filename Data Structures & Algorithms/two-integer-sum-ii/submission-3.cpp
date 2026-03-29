class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] + nums[r] < target) {
                l++;
            }
            else if (nums[l] + nums[r] > target) {
                r--;
            }
            else {
                return vector<int>({l + 1, r + 1});
            }
        }

        return {};        
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return ans(nums, 0, -1);
    }

    int ans(vector<int>& nums, int index, int prevIndex) {
        if (index >= nums.size()) {
            return 0;
        }
        
        int ifNotPicked = ans(nums, index + 1, prevIndex);
        int ifPicked = -1;
        if ((prevIndex == -1) || (nums[index] > nums[prevIndex])) {
            ifPicked = 1 + ans(nums, index + 1, index);
        }
        
        return max(ifPicked, ifNotPicked);
    }
};
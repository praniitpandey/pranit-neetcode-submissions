class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> cache(nums.size(), vector<int>(nums.size() + 1, -1));
        return ans(nums, 0, -1, cache);
    }

    int ans(vector<int>& nums, int index, int prevIndex, vector<vector<int>>& cache) {
        if (index >= nums.size()) {
            return 0;
        }
        if (cache[index][prevIndex + 1] != -1) {
            return cache[index][prevIndex + 1];
        }
        
        int ifNotPicked = ans(nums, index + 1, prevIndex, cache);
        int ifPicked = -1;
        if ((prevIndex == -1) || (nums[index] > nums[prevIndex])) {
            ifPicked = 1 + ans(nums, index + 1, index, cache);
        }
        
        cache[index][prevIndex + 1] = max(ifPicked, ifNotPicked);
        return cache[index][prevIndex + 1];
    }
};
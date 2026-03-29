class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<unordered_map<int, int>> cache(nums.size());
        return ans(nums, 0, INT_MIN, cache);
    }

    int ans(vector<int>& nums, int index, int prevMax, vector<unordered_map<int, int>>& cache) {
        if (index >= nums.size()) {
            return 0;
        }
        if (cache[index].find(prevMax) != cache[index].end()) {
            return cache[index][prevMax];
        }
        
        int ifNotPicked = ans(nums, index + 1, prevMax, cache);
        int ifPicked = -1;
        if (nums[index] > prevMax) {
            ifPicked = 1 + ans(nums, index + 1, nums[index], cache);
        }
        
        cache[index][prevMax] = max(ifPicked, ifNotPicked);
        return cache[index][prevMax];
    }
};
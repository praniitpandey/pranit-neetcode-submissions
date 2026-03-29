class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        map<pair<int, int>, int> cache;
        return ans(nums, 0, INT_MIN, cache);
    }

    int ans(vector<int>& nums, int index, long long maxSoFar, map<pair<int, int>, int>& cache) {
        if (index >= nums.size()) {
            return 0;
        }
        if (cache.count({index, (int)maxSoFar})) return cache[{index, (int)maxSoFar}];
        
        int ifNotPicked = ans(nums, index + 1, maxSoFar, cache);
        int ifPicked = -1;
        if (nums[index] > maxSoFar) {
            ifPicked = 1 + ans(nums, index + 1, nums[index], cache);
        }
        
        return cache[{index, (int)maxSoFar}] = max(ifPicked, ifNotPicked);
    }
};
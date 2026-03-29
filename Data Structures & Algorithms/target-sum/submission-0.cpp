class Solution {
  public:
    int findTargetSumWays(vector<int>& nums, int diff) {
        // Code here
        long long sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        if ((sum + diff) % 2 != 0) {
            return 0;
        }
        else {
            int target = (sum + diff) / 2;
            vector<unordered_map<int, int>> cache(nums.size() + 1);
            return countSubsets(nums, 0, target, cache);
        }
    }
    
    int countSubsets(const vector<int>& nums, int index, const long long target, vector<unordered_map<int, int>>& cache) {
        if (index == nums.size()) {
            return (target == 0) ? 1 : 0;
        }
        if (cache[index].find(target) == cache[index].end()) {
            int ifNotPicked = countSubsets(nums, index + 1, target, cache);
            int ifPicked = 0;
            
            if (nums[index] <= target) {
                ifPicked = countSubsets(nums, index + 1, target - nums[index], cache);
            }
            
            cache[index][target] = ifPicked + ifNotPicked;
        }
        
        return cache[index][target];
    }
};
class Solution {
    public boolean canPartition(int[] nums) {
        long sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 == 1) {
            return false;
        }
        else {
            Map<String, Boolean> dp = new HashMap<>();
            return dfs(nums, sum/2, 0, dp);
        }
    }

    private boolean dfs(int[] nums, long target, int index, Map<String, Boolean> dp) {
        if (target == 0) {
            return true;
        }
        if (index == nums.length || target < 0) {
            return false;
        }
        String key = target + "," + index;
        if (dp.containsKey(key)) {
            return dp.get(key);
        }

        boolean ifPicked = false;
        if (nums[index] <= target) {
            ifPicked = dfs(nums, target - nums[index], index + 1, dp);
        }
        
        boolean ifNotPicked = ifPicked ? true : dfs(nums, target, index + 1, dp);

        dp.put(key, (ifPicked || ifNotPicked));
        return dp.get(key);
    }
}
class Solution {
    public int rob(int[] nums) {
        int choice1 = robStraight(Arrays.copyOfRange(nums, 1, nums.length));
        int choice2 = robStraight(Arrays.copyOfRange(nums, 0, nums.length - 1));

        return Math.max(nums[0], Math.max(choice1, choice2));
    }

    private int robStraight(int[] nums) {
        int n = nums.length;

        if (n == 0) {
            return 0;
        }
        int dp1 = nums[0];
        if (n == 1) {
            return dp1;
        }

        int dp2 = Math.max(nums[0], nums[1]);
        if (n == 2) {
            return dp2;
        }

        int dp3 = Math.max(nums[0] + nums[2], nums[1]);
        if (n == 3) {
            return dp3;
        }

        int dp4 = 0;
        for (int i = 3; i < n; i++) {
            dp4 = Math.max(nums[i] + dp2, dp3);
            dp1 = dp2;
            dp2 = dp3;
            dp3 = dp4;
        }

        return dp4;
    }
}

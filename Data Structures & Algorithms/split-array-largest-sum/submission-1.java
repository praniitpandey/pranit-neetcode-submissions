class Solution {
    public int splitArray(int[] nums, int k) {
        int left = 0, right = 0, mid = 0, ans = Integer.MAX_VALUE;

        for (int num : nums) {
            left = Math.max(left, num);
            right += num;
        }

        while (left <= right) {
            mid = (left + right)/2;

            if (canSplit(nums, k, mid)) {
                ans = Math.min(ans, mid);
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }

    private boolean canSplit(int[] nums, int k, int maxSum) {
        int sum = 0, subarrays = 1;

        for (int num : nums) {
            if (sum + num > maxSum) {
                sum = num;
                subarrays++;
            }
            else {
                sum += num;
            }
        }

        return subarrays <= k;
    }
}
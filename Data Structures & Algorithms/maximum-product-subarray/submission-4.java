class Solution {
    public int maxProduct(int[] nums) {
        int minSoFar = nums[0], maxSoFar = nums[0], maxProduct = nums[0];

        for (int i = 1; i < nums.length; i++) {
            int tempMax = maxSoFar * nums[i];

            maxSoFar = Math.max(Math.max(maxSoFar * nums[i], minSoFar * nums[i]), nums[i]);
            minSoFar = Math.min(Math.min(tempMax, minSoFar * nums[i]), nums[i]);
            maxProduct = Math.max(maxProduct, maxSoFar);
        }
        return maxProduct;
    }
}

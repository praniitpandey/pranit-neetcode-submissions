class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> hs = new HashSet<>();
        for (int num : nums)
            hs.add(num);

        int count = 0, maxCount = 0;
        for (int num : hs) {
            if (hs.contains(num - 1)) {
                continue;
            }
            else {
                count = 1;
                while (hs.contains(num + 1)) {
                    ++num;
                    ++count;
                }

                maxCount = Math.max(count, maxCount);
            }
        }

        return maxCount;
    }
}

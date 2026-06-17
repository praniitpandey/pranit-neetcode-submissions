class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> freq = new HashMap<>();
        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        List<Integer> ans = new ArrayList<>();
        for (int num : freq.keySet()) {
            if (freq.get(num) > (n/3)) {
                ans.add(num);
            }
        }
        return ans;
    }
}
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> freq = new HashMap<>();
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            freq.put(s.charAt(right), freq.getOrDefault(s.charAt(right), 0) + 1);

            while (freq.getOrDefault(s.charAt(right), 0) > 1) {
                freq.put(s.charAt(left), freq.getOrDefault(s.charAt(left), 0) - 1);
                ++left;
            }

            maxLength = Math.max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
}

class Solution {
    public int characterReplacement(String s, int k) {
        Map<Character, Integer> freq = new HashMap<>();
        int left = 0;
        int maxFreq = 0, maxLength = 1;

        for (int right = 0; right < s.length(); right++) {
            freq.put(s.charAt(right), freq.getOrDefault(s.charAt(right), 0) + 1);
            maxFreq = Math.max(maxFreq, freq.get(s.charAt(right)));

            while ((right - left + 1) - maxFreq > k) {
                freq.put(s.charAt(left), freq.get(s.charAt(left)) - 1);
                left++;
            }

            maxLength = Math.max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
}

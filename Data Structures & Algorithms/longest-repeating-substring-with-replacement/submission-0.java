class Solution {
    public int characterReplacement (String s, int k) {
        int ans = 1;
        for (char c = 'A'; c <= 'Z'; c++) {
            int i = 0;
            Map<Character, Integer> freq = new HashMap<>();
            for (int j = 0; j < s.length(); j++) {
                freq.put(s.charAt(j), freq.getOrDefault(s.charAt(j), 0) + 1);
                while (j - i + 1 - freq.getOrDefault(c, 0) > k) {
                    freq.put(s.charAt(i), freq.get(s.charAt(i)) - 1);
                    i++;
                }
                ans = Math.max(ans, j - i + 1);
            }
        }
        return ans;
    }
}

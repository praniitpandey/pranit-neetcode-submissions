class Solution {
    public boolean canPermutePalindrome(String s) {
        int[] freqs = new int[26];

        for (char c : s.toCharArray())
            ++freqs[c - 'a'];

        int oddFreqs = 0;
        for (int freq : freqs)
            if (freq % 2 == 1)
                ++oddFreqs;

        return oddFreqs < 2;
    }
}

class Solution {
    public boolean checkInclusion(String s1, String s2) {
        if (s2.length() < s1.length())
            return false;

        int[] freq1 = new int[26];
        Arrays.fill(freq1, 0);
        for (int i = 0; i < s1.length(); i++)
            ++freq1[s1.charAt(i) - 'a'];


        int[] freq2 = new int[26];
        Arrays.fill(freq2, 0);
        for (int i = 0; i < s1.length(); i++)
            ++freq2[s2.charAt(i) - 'a'];

        for (int left = 0, right = s1.length() - 1; right < s2.length(); left++, right++) {
            if (compareFreq(freq1, freq2))
                return true;

            --freq2[s2.charAt(left) - 'a'];
            if (right + 1 < s2.length())
                ++freq2[s2.charAt(right + 1) - 'a'];
        }

        return false;
    }

    private boolean compareFreq(int[] freq1, int[] freq2) {
        for (int i = 0; i < 26; i++)
            if (freq1[i] != freq2[i])
                return false;

        return true;
    }
}

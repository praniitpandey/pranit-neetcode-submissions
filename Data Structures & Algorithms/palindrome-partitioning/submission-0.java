class Solution {
    public List<List<String>> partition(String s) {
        n = s.length();
        int left, right;

        boolean[][] isPali = new boolean[n][n];
        for (boolean[] row : isPali)
            Arrays.fill(row, false);

        isPali[0][0] = true;
        for (int i = 1; i < n; i++) {
            //for even length substrings
            left = i - 1; right = i;
            while (left >= 0 && right < n && s.charAt(left) == s.charAt(right))
                isPali[left--][right++] = true;

            //for odd length substrings
            left = i; right = i;
            while (left >= 0 && right < n && s.charAt(left) == s.charAt(right))
                isPali[left--][right++] = true;
        }

        solve(s, isPali, 0);

        return parts;
    }

    private List<String> part = new ArrayList<String>();
    private List<List<String>> parts = new ArrayList<List<String>>();
    private int n;

    private void solve(final String s, final boolean[][] isPali, int left) {
        if (left == n) {
            parts.add(new ArrayList<>(part));
            return;
        }

        for (int right = left; right < n; right++) {
            if (isPali[left][right]) {
                part.add(s.substring(left, right + 1));
                solve(s, isPali, right + 1);
                part.removeLast();
            }
        }
    }
}

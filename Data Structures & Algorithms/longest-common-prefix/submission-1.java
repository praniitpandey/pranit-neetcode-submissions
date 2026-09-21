class Solution {
    public String longestCommonPrefix(String[] strs) {
        int minLength = strs[0].length();

        for (int i = 1; i < strs.length; i++)
            minLength = Math.min(minLength, strs[i].length());

        StringBuilder ans = new StringBuilder();
        for (int j = 0; j < minLength; j++) {
            boolean allSame = true;
            char c = strs[0].charAt(j);

            for (int i = 1; i < strs.length; i++) {
                if (strs[i].charAt(j) != c) {
                    allSame = false;
                    break;
                }
            }

            if (allSame) {
                ans.append(c);
            }
            else {
                break;
            }
        }

        return ans.toString();
    }
}
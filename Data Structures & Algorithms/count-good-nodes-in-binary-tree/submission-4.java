/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    public int goodNodes(TreeNode root) {
        return dfs(root, root.val);
    }

    public int dfs(TreeNode root, int maxSoFar) {
        if (root == null)
            return 0;

        int ans = dfs(root.left, Math.max(maxSoFar, root.val)) + dfs(root.right, Math.max(maxSoFar, root.val));

        if (root.val >= maxSoFar)
            ++ans;

        return ans;
    }
}

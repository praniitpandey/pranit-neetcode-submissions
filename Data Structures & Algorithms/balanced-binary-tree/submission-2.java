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
    public boolean isBalanced(TreeNode root) {
        boolean[] result = new boolean[1];
        result[0] = true;

        dfs(root, result);
        return result[0];
    }

    int dfs(TreeNode root, boolean[] result) {
        if (root == null) {
            return 0;
        }
        int leftHeight = dfs(root.left, result);
        int rightHeight = dfs(root.right, result);

        if (Math.abs(leftHeight - rightHeight) > 1) {
            result[0] = false;
        }

        return 1 + Math.max(leftHeight, rightHeight);
    }
}

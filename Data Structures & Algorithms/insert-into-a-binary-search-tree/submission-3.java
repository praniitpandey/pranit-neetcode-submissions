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
    public TreeNode insertIntoBST(TreeNode root, int num) {
        if (root == null) {
            return new TreeNode(num);
        }
        else if (num < root.val) {
            root.left = insertIntoBST(root.left, num);
        }
        else if (num > root.val) {
            root.right = insertIntoBST(root.right, num);
        }
        return root;
    }
}
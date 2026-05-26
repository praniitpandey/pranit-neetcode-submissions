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
    public int rob(TreeNode root) {
        Map<TreeNode, Integer> dp = new HashMap<TreeNode, Integer>();
        return dfs(root, dp);
    }
    public int dfs(TreeNode root, Map<TreeNode, Integer> dp) {
        if (root == null) {
            return 0;
        }

        if (dp.containsKey(root)) {
            return dp.get(root);
        }

        int ifRobbed = root.val;
        int ifSkipped = 0;

        if (root.left != null) {
            ifSkipped += dfs(root.left, dp);
            ifRobbed += (dfs(root.left.left, dp) + dfs(root.left.right, dp));
        }
        if (root.right != null) {
            ifSkipped += dfs(root.right, dp);
            ifRobbed += (dfs(root.right.left, dp) + dfs(root.right.right, dp));
        }

        dp.put(root, Math.max(ifRobbed, ifSkipped));
        return dp.get(root);
    }
}
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
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) {
            return new ArrayList<List<Integer>>();
        }

        List<List<Integer>> levels = new ArrayList<>();
        Queue<TreeNode> bfs = new ArrayDeque<>();
        bfs.add(root);

        while (!bfs.isEmpty()) {
            List<Integer> level = new ArrayList<>();
            int size = bfs.size();

            for (int i = 0; i < size; i++) {
                TreeNode currentNode = bfs.poll();
                level.add(currentNode.val);

                if (currentNode.left != null) {
                    bfs.add(currentNode.left);
                }
                if (currentNode.right != null) {
                    bfs.add(currentNode.right);
                }
            }

            levels.add(level);
        }

        return levels;
    }
}

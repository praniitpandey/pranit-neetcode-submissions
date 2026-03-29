/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root) {
            int ifPassesThroughRoot = heightOfBinaryTree(root->left) + heightOfBinaryTree(root->right);
            int ifInLeftSubtree = diameterOfBinaryTree(root->left);
            int ifInRightSubtree = diameterOfBinaryTree(root->right);

            return max({ifPassesThroughRoot, ifInLeftSubtree, ifInRightSubtree});
        }
        else {
            return 0;
        }
        
    }

    int heightOfBinaryTree(TreeNode* root) {
        if (root) {
            return 1 + max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right));
        }
        else {
            return 0;
        }
    }
};

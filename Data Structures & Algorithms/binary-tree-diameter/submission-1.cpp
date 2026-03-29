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
        int result = 0;
        dfs(root, result);
        return result;
    }

    int dfs(TreeNode* root, int& result) {
        if (root) {
            int heightOfLeftSubtree = dfs(root->left, result);
            int heightOfRightSubtree = dfs(root->right, result);
            result = max(result, heightOfLeftSubtree + heightOfRightSubtree);
            return 1 + max(heightOfLeftSubtree, heightOfRightSubtree);
        }
        else {
            return 0;
        }
    }
};

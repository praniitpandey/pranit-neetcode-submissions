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
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return dfs(root, -101);
    }

    int dfs(TreeNode* root, int maxVal) {
        if (!root) {
            return 0;
        }
        else if (root->val < maxVal) {
            return dfs(root->left, max(root->val, maxVal)) + dfs(root->right, max(root->val, maxVal));
        }
        else {
            return 1 + dfs(root->left, max(root->val, maxVal)) + dfs(root->right, max(root->val, maxVal));
        }
    }
};

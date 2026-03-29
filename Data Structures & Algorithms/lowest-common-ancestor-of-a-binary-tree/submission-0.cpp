/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root == p || root == q) {
            return root;
        }

        TreeNode* searchLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode* searchRight = lowestCommonAncestor(root->right, p, q);

        if (searchLeft && searchRight) {
            return root;
        }
        else if (searchLeft && !searchRight) {
            return searchLeft;
        }
        else if (!searchLeft && searchRight) {
            return searchRight;
        }
        else {
            return nullptr;
        }
    }
};
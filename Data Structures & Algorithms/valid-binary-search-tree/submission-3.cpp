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
    bool isValidBST(TreeNode* root, int left = INT_MIN, int right = INT_MAX) {
        if (!root) {
            return true;
        }
        else if ((left < root->val) && (root->val < right)) {
            return isValidBST(root->left, left, root->val) && isValidBST(root->right, root->val, right);
        }
        else {
            return false;
        }
    }
};

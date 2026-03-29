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
    TreeNode* insertIntoBST(TreeNode* root, int num) {
        if (!root) {
            TreeNode* newNode = new TreeNode(num);
            return newNode;
        }
        else if (num < root->val) {
            if (!root->left) {
                TreeNode* newNode = new TreeNode(num);
                root->left = newNode;
            }
            else {
                root->left = insertIntoBST(root->left, num);
            }
        }
        else if (num > root->val) {
            if (!root->right) {
                TreeNode* newNode = new TreeNode(num);
                root->right = newNode;
            }
            else {
                root->right = insertIntoBST(root->right, num);
            }
        }
        
        return root;
    }
};
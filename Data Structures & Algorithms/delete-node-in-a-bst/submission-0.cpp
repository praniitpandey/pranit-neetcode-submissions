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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return nullptr;
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else {
            if (!root->left && !root->right) {
                return nullptr;
            }
            else if (!root->left) {
                return root->right;
            }
            else if (!root->right) {
                return root->left;
            }
            else {
                TreeNode* successor = root->right;
                while (successor->left) {
                    successor = successor->left;
                }
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
};
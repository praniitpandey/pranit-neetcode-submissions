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
    bool isValidBST(TreeNode* root) {
        if (root) {
            return (maxValue(root->left) < root->val) 
                && (minValue(root->right) > root->val) 
                && (isValidBST(root->left)) 
                && (isValidBST(root->right));
        }
        else {
            return true;
        }
    }

    int minValue(TreeNode* root) {
        if (root) {
            return min({root->val, minValue(root->left), minValue(root->right)});
        }
        else {
            return INT_MAX;
        }
    }

    int maxValue(TreeNode* root) {
        if (root) {
            return max({root->val, maxValue(root->left), maxValue(root->right)});
        }
        else {
            return INT_MIN;
        }
    }
};

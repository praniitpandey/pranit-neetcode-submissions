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
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        dfs(root, result);
        return result;
    }

    int dfs(TreeNode* root, int& result) {
        if (root == nullptr) {
            return 0;
        }
        int leftGain = max(0, dfs(root->left, result));
        int rightGain = max(0, dfs(root->right, result));

        result = max(result, root->val + leftGain + rightGain);
        return root->val + max(leftGain, rightGain);
    }
};

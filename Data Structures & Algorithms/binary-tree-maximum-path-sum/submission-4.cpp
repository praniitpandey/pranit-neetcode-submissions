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
        maxPathOverall = INT_MIN;
        dfs(root);

        return maxPathOverall;
    }

private:
    int maxPathOverall;

    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftGain = max(dfs(root->left), 0);
        int rightGain = max(dfs(root->right), 0);

        maxPathOverall = max(root->val + leftGain + rightGain, maxPathOverall);

        return root->val + max(leftGain, rightGain);
    }
};

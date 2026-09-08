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

        int leftGain = dfs(root->left);
        int rightGain = dfs(root->right);

        int maxPathHere = root->val + max(0, leftGain) + max(0, rightGain);
        maxPathOverall = max(maxPathHere, maxPathOverall);

        return root->val + max({0, leftGain, rightGain});
    }
};

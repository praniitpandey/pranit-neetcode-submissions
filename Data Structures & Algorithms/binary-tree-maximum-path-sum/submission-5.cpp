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
        if (root == nullptr)
            return 0;

        ans = INT_MIN;
        dfs(root);

        return ans;
    }
private:
    int ans;

    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftGain = max(0, dfs(root->left));
        int rightGain = max(0, dfs(root->right));

        ans = max(ans, root->val + leftGain + rightGain);

        return root->val + max(leftGain, rightGain);
    }
};

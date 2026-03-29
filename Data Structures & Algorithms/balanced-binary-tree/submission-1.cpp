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
    bool isBalanced(TreeNode* root) {
        bool result = true;
        dfs(root, result);
        return result;
    }

    int dfs(TreeNode* root, bool& result) {
        if (root) {
            int heightOfLeftSubtree = dfs(root->left, result);
            int heightOfRightSubtree = dfs(root->right, result);
            if (abs(heightOfLeftSubtree - heightOfRightSubtree) > 1) {
                result = false;
            }
            return 1 + max(heightOfLeftSubtree, heightOfRightSubtree);
        }
        else {
            return 0;
        }
    }
};

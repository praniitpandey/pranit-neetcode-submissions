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
    int goodNodes(TreeNode* root) {
        int count = 0;
        countGoodNodes(root, -1e9, count);

        return count;
    }

private:
    void countGoodNodes(TreeNode* root, int maxSoFar, int& count) {
        if (root == nullptr) return;

        if (root->val >= maxSoFar) ++count;

        maxSoFar = max(root->val, maxSoFar);

        countGoodNodes(root->left, maxSoFar, count);
        countGoodNodes(root->right, maxSoFar, count);
    }
};

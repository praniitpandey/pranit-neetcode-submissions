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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        dfs(root, inorder);
        return inorder[k-1];
    }

    void dfs(TreeNode* root, vector<int>& store) {
        if (root) {
            dfs(root->left, store);
            store.push_back(root->val);
            dfs(root->right, store);
        }
        else {
            return;
        }
    }
};

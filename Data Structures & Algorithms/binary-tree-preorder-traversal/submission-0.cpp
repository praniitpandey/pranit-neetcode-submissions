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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> solution;
        traverse(root, solution);
        return solution;        
    }

    void traverse(TreeNode* root, vector<int>& store) {
        if (root == nullptr) {
            return;
        }
        store.push_back(root->val);
        traverse(root->left, store);
        traverse(root->right, store);
    }
};
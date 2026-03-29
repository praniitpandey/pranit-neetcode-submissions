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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> cache;
        return dfs(root, cache);
    }

    int dfs(TreeNode* root, unordered_map<TreeNode*, int>& cache) {
        if (!root) {
            return 0;
        }
        if (cache.find(root) != cache.end()) {
            return cache[root];
        }

        int ifRobbed = INT_MIN, ifSkipped = INT_MIN;
        
        if (root && root->left && root->right) {
            ifRobbed = root->val 
                + dfs(root->left->left, cache) 
                + dfs(root->left->right, cache) 
                + dfs(root->right->left, cache) 
                + dfs(root->right->right, cache);
            ifSkipped = dfs(root->left, cache) + dfs(root->right, cache);
        }
        else if (root && root->left && !root->right) {
            ifRobbed = root->val 
                + dfs(root->left->left, cache) 
                + dfs(root->left->right, cache);
            ifSkipped = dfs(root->left, cache);
        }
        else if (root && !root->left && root->right) {
            ifRobbed = root->val 
                + dfs(root->right->left, cache)
                + dfs(root->right->right, cache);
            ifSkipped = dfs(root->right, cache);
        }
        else if (root && !root->left && !root->right) {
            ifRobbed = root->val;
        }

        cache[root] = max(ifRobbed, ifSkipped);
        return cache[root];
    }
};
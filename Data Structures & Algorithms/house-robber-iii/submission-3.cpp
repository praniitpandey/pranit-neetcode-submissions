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

private:
    int dfs(TreeNode* root, unordered_map<TreeNode*, int>& cache) {
        if (!root) {
            return 0;
        }
        if (cache.find(root) != cache.end()) {
            return cache[root];
        }

        int ifRobbed = root->val, ifSkipped = 0;
        if (root->left) {
            ifRobbed += (dfs(root->left->left, cache) + dfs(root->left->right, cache));
            ifSkipped += dfs(root->left, cache);
        }

        if (root->right) {
            ifRobbed += (dfs(root->right->left, cache) + dfs(root->right->right, cache));
            ifSkipped += dfs(root->right, cache);
        }

        cache[root] = max(ifRobbed, ifSkipped);
        return cache[root];
    }
};
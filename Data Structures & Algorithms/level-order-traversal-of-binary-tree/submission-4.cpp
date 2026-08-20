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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        
        if (root == nullptr)
            return levels;

        queue<TreeNode*> bfs;
        bfs.push(root);
        
        while (!bfs.empty()) {
            vector<int> level;

            int levelSize = bfs.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = bfs.front();
                bfs.pop();

                level.push_back(curr->val);
                if (curr->left) bfs.push(curr->left);
                if (curr->right) bfs.push(curr->right);
            }
            levels.push_back(level);
        }

        return levels;
    }
};
